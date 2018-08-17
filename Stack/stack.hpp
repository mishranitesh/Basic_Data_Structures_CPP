#ifndef NITESH_STACK_HPP
#define NITESH_STACK_HPP

/*
 * Namespace to contain implementation of Stack Data Structure
 */
namespace nm {

    /*
     * Class to represent Stack and contains implementation
     * Implement Stack using Linked List (LIFO)
     */
    class Stack {
    public:

        /*
        * Inner class to represent Node of stack
        */
        class Node {
        public:

            // Constructors, Assignment Operator and Destructor
            Node() : _data{-9999}, _next{nullptr} {}
            Node(int data) : _data{data}, _next{nullptr} {}
            ~Node() {
                _next = nullptr;
                _data = -9999;
            }
            Node(const Node &) = delete;
            Node &operator=(const Node &) = delete;

            // Public Member Variables
            int _data;
            Node *_next;
        };

        // Contructors, Assignment Operator and Destructor
        Stack() : _head{nullptr}, _size{0} {}
        ~Stack();
        Stack(const Stack &);
        Stack &operator=(const Stack &);

        // Public Member Functions
        void push(int data);
        void push_back(int data);
        void pop();
        const int &peek();
        bool operator==(const Stack &);

        /*
         * Inner class to represent iterator
         */
        class Iterator {
        public:

            // Constructors and Destructor
            Iterator(const Iterator &iter) : _iter_ptr{iter._iter_ptr} {}
            Iterator(Node *ptr) : _iter_ptr{ptr} {}

            // Dereference *operator
            int &operator*() const {
                return _iter_ptr->_data;
            }

            // Pre increment operator
            Iterator &operator++() {
                if (_iter_ptr != nullptr) {
                    _iter_ptr = _iter_ptr->_next;
                }
                return *this;
            }

            // Post increment operator
            Iterator operator++(int) {
                Iterator temp_iter{*this};
                if (_iter_ptr != nullptr) {
                    _iter_ptr = _iter_ptr->_next;
                }
                return temp_iter;
            }

            // Public Member Variables
            Node *_iter_ptr;
        };

        // Public Inline Member Functions
        int size() { return _size; }

        bool isEmpty() { return (_size == 0); }

        Iterator begin() {
            return Iterator{_head};
        }

        Iterator end() {
            return Iterator{nullptr};
        }

        friend bool operator!=(const Iterator &iter_1, const Iterator &iter_2) {
            return (iter_1._iter_ptr != iter_2._iter_ptr);
        }

    private:

        // Private Member Variables
        Node *_head;
        int _size;
    };

    // Value constructor definition
    Stack::Stack(const Stack &stk) : _head{nullptr}, _size{0} {
        Node *t_node = stk._head;
        while (t_node != nullptr) {
            this->push_back(t_node->_data);
            t_node = t_node->_next;
        }
    }

    // Assignment =operator definition
    Stack &Stack::operator=(const Stack &stk) {

        //Self-assignment
        if (this == &stk) return *this;

        // Delete old contents
        while (_head != nullptr) {
            Node *t_node = _head->_next;
            delete _head;
            _head = t_node;
        }
        // Copy elements
        _size = 0;
        Node *t_node = stk._head;
        while (t_node != nullptr) {
            this->push_back(t_node->_data);
            t_node = t_node->_next;
        }

        return *this;
    }

    // Destructor definition
    Stack::~Stack() {
        while (_head != nullptr) {
            Node *t_node = _head->_next;
            delete _head;
            _head = t_node;
        }
        _size = 0;
    }

    // Push function definition
    void Stack::push(int data) {
        if (_head == nullptr) {
            _head = new Node(data);
        } else {
            Node *t_head = _head;
            _head = new Node(data);
            _head->_next = t_head;
        }
        ++_size;

        return;
    }

    // Push_Back function definition
    void Stack::push_back(int data) {
        if (_head == nullptr) {
            _head = new Node(data);
        } else {
            Node *t_node = _head;
            while (t_node->_next != nullptr) {
                t_node = t_node->_next;
            }
            t_node->_next = new Node(data);
        }
        ++_size;

        return;
    }

    // Pop function definition
    void Stack::pop() {
        if (_head == nullptr) {
            return;
        }
        if (_head->_next == nullptr) {
            delete _head;
            _head = nullptr;
        } else {
            Node *t_node = _head->_next;
            delete _head;
            _head = t_node;
        }
        --_size;

        return;
    }

    // Peek function definition
    const int &Stack::peek() {
        return _head->_data;
    }

    // Overloaded ==operator function definition
    bool Stack::operator==(const Stack &stk) {

        // Corner cases
        if (this == &stk) return true;
        if (this->_size != stk._size) return false;

        Node *t_node1 = this->_head;
        Node *t_node2 = stk._head;

        // Element by element comparison
        while (t_node1 != nullptr) {
            if (t_node1->_data != t_node2->_data) {
                return false;
            }
            t_node1 = t_node1->_next;
            t_node2 = t_node2->_next;
        }
        return true;
    }
}

#endif