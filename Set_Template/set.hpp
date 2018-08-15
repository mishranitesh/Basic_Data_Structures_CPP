#ifndef NITESH_SET_HPP
#define NITESH_SET_HPP

#include <vector>

/*
 * Namespace to contain implementation of Set Data Structure
 */
namespace nm {

    /*
     * Template Class to represent Set and contains implementation
     */
    template<typename T>
    class Set {
    public:

        // Contructors, Assignment Operator and Destructor
        Set() : _root{0}, _size{0} {}

        // Using post-order traversal for deleting elements
        ~Set() {
            postordertraversal(_root);
            _root = nullptr;
        }

        // Using preorder traversal for coping elements
        Set(const Set &o_set) : _root{0}, _size{0} {
            preordertraversal(o_set._root);
        }

        Set &operator=(const Set &) = default;

        // Public Member Functions
        void insert(T);

        // Public Inline Member Functions
        int size() { return _size; }
        bool empty() { return (_size == 0); }

        /*
         * Inner class to represent Node of set
         */
        class Node {
        public:
            T _data;
            Node *_left;
            Node *_right;
            Node *_parent;

            Node() : _left{0}, _right{0}, _parent{0} {}
            ~Node() {
                _left = nullptr;
                _right = nullptr;
                _parent = nullptr;
            }
            Node(T data) : _left{0}, _right{0}, _parent{0} {
                _data = data;
            }

            Node(const Node &node) = default;
            Node &operator=(const Node &) = default;
        };

        /*
         * Inner class to represent iterator
         */
        class Iterator {
        public:

            // Contructors, Assignment Operator and Destructor
            Iterator() = delete;
            Iterator &operator=(const Iterator &) = delete;
            ~Iterator() = default;
            Iterator(const Iterator &iter) {
                _list = iter._list;
                _index = iter._index;
            }
            Iterator(std::vector <T> list, int index) {
                _list = list;
                _index = index;
            }

            // Dereference operator
            T operator*() const {
                return _list[_index];
            }

            // Pre increment operator
            Iterator &operator++() {
                ++_index;
                return *this;
            }

            // Post increment operator
            Iterator operator++(int) {
                Set<T>::Iterator temp_iter{*this};
                ++_index;
                return temp_iter;
            }

            // Public Member variables
            std::vector <T> _list;
            int _index;

        };

        // Begin function definition
        Iterator begin() {
            std::vector <T> list;
            inordertraversal(list, this->_root);
            return Iterator{list, 0};
        }

        // End function definition
        Iterator end() {
            std::vector <T> list;
            inordertraversal(list, this->_root);
            return Iterator{list, _size};
        }

        // Overloaded !=operator definition
        friend bool operator!=(const Iterator &iter_1, const Iterator &iter_2) {
            return (iter_1._index != iter_2._index);
        }

        bool operator==(const Set &);

    private:
        Node *_root;
        int _size;

        // Private Member functions
        void insert(Node *, T);
        void preordertraversal(Node *);
        void postordertraversal(Node *);
        void inordertraversal(std::vector <T> &list, Node *);
    };

    // Insert function definition
    template<typename T>
    void Set<T>::insert(Node *node, T data) {
        if (data < node->_data) {
            if (node->_left == nullptr) {
                Node *n_node = new Node(data);
                n_node->_parent = node;
                node->_left = n_node;
                ++_size;
                return;
            } else {
                insert(node->_left, data);
            }
        } else if (data > node->_data) {
            if (node->_right == nullptr) {
                Node *n_node = new Node(data);
                n_node->_parent = node;
                node->_right = n_node;
                ++_size;
                return;
            } else {
                insert(node->_right, data);
            }
        } else {
            return;
        }
    }

    // Insert function definition
    template<typename T>
    void Set<T>::insert(T data) {
        if (_root == nullptr) {
            _root = new Node(data);
            ++_size;
        } else {
            insert(_root, data);
        }
    }

    // Pre-Order Traversal function definition
    template<typename T>
    void Set<T>::preordertraversal(Node *node) {
        if (node != nullptr) {
            insert(node->_data);
            preordertraversal(node->_left);
            preordertraversal(node->_right);
        }
    }

    // Post-Order Traversal function definition
    template<typename T>
    void Set<T>::postordertraversal(Node *node) {
        if (node != nullptr) {
            postordertraversal(node->_left);
            postordertraversal(node->_right);
            delete node;
        }
    }

    // In-Order Traversal function definition
    template<typename T>
    void Set<T>::inordertraversal(std::vector <T> &list, Node *node) {
        if (node != nullptr) {
            inordertraversal(list, node->_left);
            list.push_back(node->_data);
            inordertraversal(list, node->_right);
        }
    }

    // Overloaded ==operator function definition
    template<typename T>
    bool Set<T>::operator==(const Set &o_set) {
        if (this == &o_set) return true;
        if (this->_size != o_set._size) return false;

        std::vector <T> list1, list2;
        inordertraversal(list1, this->_root);
        inordertraversal(list2, o_set._root);

        return (list1 == list2);
    }
}

#endif