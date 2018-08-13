#ifndef NITESH_LIST_HPP
#define NITESH_LIST_HPP

/*
 * Namespace to contain implementation of List Data Structure
 */
namespace nm {

    /*
     * Template Class to represent List and contains implementation
     */
    template<typename T>
    class List {
    public:

        /*
         * Inner class to represent Node of the list
         */
        class Node {
        public:

            // Constructors and Destructor
            Node() = delete;
            Node(T data) : _data{data}, _next{0} {}
            ~Node() { _next = nullptr; }

            // Public Member Variables
            T _data;
            Node *_next;
        };

        /*
         * Inner class to represent iterator
         */
        class Iterator {
        public:

            // Constructors and Destructor
            Iterator() = delete;
            Iterator(const Iterator &iter) : _ptr{iter._ptr} {}
            Iterator(Node *node_ptr) : _ptr{node_ptr} {}
            ~Iterator() {}

            // Dereference *operator
            T &operator*() const {
                return _ptr->_data;
            }

            // Pre increment operator
            Iterator &operator++() {
                if (_ptr != nullptr) {
                    _ptr = _ptr->_next;
                }
                return *this;
            }

            // Post increment operator
            Iterator operator++(int) {
                List<T>::Iterator temp_iter{*this};
                if (_ptr != nullptr) {
                    _ptr = _ptr->_next;
                }
                return temp_iter;
            }

            // Public Member Variables
            List<T>::Node *_ptr;
        };

        // Contructors, Assignment Operator and Destructor
        List();
        ~List();
        List(const List &) = delete;
        List &operator=(const List &) = delete;

        // Public Member Functions
        void push_front(T);
        void push_back(T);
        void erase(Iterator);

        // Public Inline Member Functions
        Iterator insert(Iterator iter, T data) {
            Node *t_head = _head;
            while (t_head->_next != nullptr && t_head->_next->_next != iter._ptr) {
                t_head = t_head->_next;
            }
            t_head = t_head->_next;
            Node *new_node = new Node(data);
            t_head->_next = new_node;
            t_head->_next->_next = iter._ptr;

            return Iterator{t_head->_next};
        }

        Iterator begin() { return Iterator{_head}; }
        Iterator end() { return Iterator{nullptr}; }

        friend bool operator!=(const Iterator &iter_1, const Iterator &iter_2) {
            return (iter_1._ptr != iter_2._ptr);
        }

    private:
        Node *_head;
    };

    // Default ctor definition
    template<typename T>
    List<T>::List() : _head{nullptr} {}

    // Destructor definition
    template<typename T>
    List<T>::~List() {
        if (_head != nullptr) {
            if (_head->_next == nullptr) {
                delete _head;
                _head = nullptr;
            } else {
                while (_head != nullptr) {
                    Node *t_head = _head->_next;
                    delete _head;
                    _head = nullptr;
                    _head = t_head;
                }
            }
        }
    }

    // Push front function definition
    template<typename T>
    void List<T>::push_front(T data) {
        if (_head == nullptr) {
            _head = new Node(data);
        } else {
            Node *t_head = _head;
            _head = new Node(data);
            _head->_next = t_head;
        }
        return;
    }

    // Push back function definition
    template<typename T>
    void List<T>::push_back(T data) {
        if (_head == nullptr) {
            _head = new Node(data);
            return;
        }
        Node *t_head = _head;
        while (t_head->_next != nullptr) {
            t_head = t_head->_next;
        }
        Node *new_node = new Node(data);
        t_head->_next = new_node;
        return;
    }

    // Erase function definition
    template<typename T>
    void List<T>::erase(List<T>::Iterator iter) {
        if (_head == iter._ptr) {
            if (_head->_next == nullptr) {
                delete _head;
                _head = nullptr;
            } else {
                Node *temp = _head->_next;
                delete _head;
                _head = nullptr;
                _head = temp;
            }
            return;
        }
        Node *t_head = _head;
        bool found = false;
        while (t_head->_next != nullptr) {
            if (t_head->_next == iter._ptr) {
                found = true;
                break;
            }
            t_head = t_head->_next;
        }
        if (found) {
            Node *temp = t_head->_next->_next;
            delete t_head->_next;
            t_head->_next = temp;
        }
    }
}

#endif