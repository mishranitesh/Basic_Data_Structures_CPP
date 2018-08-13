#ifndef NITESH_DEQUE_HPP
#define NITESH_DEQUE_HPP

#include <iostream>

namespace nm {

    /*
     * Template Class to represent Deque and contains its implementation
     */
    template<typename T>
    class Deque {
    public:

        /*
         * Inner class to represent Node of elements
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

        // Contructors, Assignment Operator and Destructor
        Deque();
        Deque(const Deque &);
        Deque &operator=(const Deque &);
        ~Deque();

        // Public Member Functions
        void push_back(T);
        void push_front(T);
        T pop_front();
        T pop_back();
        T operator[](int);
        bool operator==(const Deque &);

        // Public Inline Member Functions
        T front() { return _head->_data; }
        T back() { return _tail->_data; }
        int size() { return _size; }
        bool isEmpty() { return (_size == 0); }

        /*
         * Class to represent iterator
         */
        class Iterator {
        public:

            // Contructors and Destructor
            Iterator() = delete;
            Iterator(const Iterator &iter) : _ptr{iter._ptr} {}
            Iterator(Deque<T>::Node *node_ptr) : _ptr{node_ptr} {}
            ~Iterator() {}

            // Dereference *operator overloading
            T &operator*() const {
                return _ptr->_data;
            }

            // Pre increment
            Iterator &operator++() {
                if (_ptr != nullptr) {
                    _ptr = _ptr->_next;
                }
                return *this;
            }

            // Post increment
            Iterator operator++(int) {
                Deque<T>::Iterator temp_iter{*this};
                if (_ptr != nullptr) {
                    _ptr = _ptr->_next;
                }
                return temp_iter;
            }

            // Public Member Variable
            Deque<T>::Node *_ptr;
        };

        // Public Inline Member Function
        Iterator begin() { return Iterator{_head}; }
        Iterator end() { return Iterator{nullptr}; }

        friend bool operator!=(const Iterator &iter_1, const Iterator &iter_2) {
            return (iter_1._ptr != iter_2._ptr);
        }

    private:
        Node *_head;
        Node *_tail;
        int _size;
    };

    // Default ctor definition
    template<typename T>
    Deque<T>::Deque() : _head{0}, _tail{0}, _size{0} {}

    // Value ctor definition
    template<typename T>
    Deque<T>::Deque(const Deque<T> &deq) : _head{0}, _tail{0}, _size{0} {
        Node *t_node = deq._head;
        while (t_node != nullptr) {
            this->push_back(t_node->_data);
            t_node = t_node->_next;
        }
    }

    // Assignment operator definition
    template<typename T>
    Deque<T> &Deque<T>::operator=(const Deque<T> &deq) {
        // Self assignment
        if (this == &deq) return *this;

        // Delete elements
        if (_head == _tail) {
            delete _head;
            _head = nullptr;
            _tail = nullptr;
        } else {
            while (_head != nullptr) {
                Node *t_head = _head->_next;
                delete _head;
                _head = nullptr;
                _head = t_head;
            }
            _tail = nullptr;
        }
        _size = 0;

        // Copy elements
        Node *t_node = deq._head;
        while (t_node != nullptr) {
            this->push_back(t_node->_data);
            t_node = t_node->_next;
        }

        return *this;
    }

    // Destructor definition
    template<typename T>
    Deque<T>::~Deque() {
        if (_head == _tail) {
            delete _head;
            _head = nullptr;
            _tail = nullptr;
        } else {
            while (_head != nullptr) {
                Node *t_head = _head->_next;
                delete _head;
                _head = nullptr;
                _head = t_head;
            }
            _tail = nullptr;
        }
        _size = 0;
    }

    // Push back function definition
    template<typename T>
    void Deque<T>::push_back(T data) {
        Node *n_node = new Node(data);
        if (_head == nullptr && _tail == nullptr) {
            _head = n_node;
            _tail = n_node;
        } else {
            _tail->_next = n_node;
            _tail = _tail->_next;
        }
        ++_size;

        return;
    }

    // Push front function definition
    template<typename T>
    void Deque<T>::push_front(T data) {
        Node *n_node = new Node(data);
        if (_head == nullptr && _tail == nullptr) {
            _head = n_node;
            _tail = n_node;
        } else {
            n_node->_next = _head;
            _head = n_node;
        }
        ++_size;

        return;
    }

    // Pop back function definition
    template<typename T>
    T Deque<T>::pop_back() {
        T data;
        if (!isEmpty()) {
            data = _tail->_data;
            if (_tail == _head) {
                delete _tail;
                _tail = nullptr;
                _head = nullptr;
            } else if (_tail == _head->_next) {
                delete _tail;
                _tail = _head;
            } else {
                Node *t_node = _head;
                while (t_node->_next != _tail) {
                    t_node = t_node->_next;
                }
                t_node->_next = nullptr;
                delete _tail;
                _tail = t_node;
            }
            --_size;
        } else {
            // Throw exception
        }
        return data;
    }

    // Pop front function definition
    template<typename T>
    T Deque<T>::pop_front() {
        T data;
        if (!isEmpty()) {
            data = _head->_data;
            if (_head == _tail) {
                delete _head;
                _head = nullptr;
                _tail = nullptr;
            } else if (_head->_next == _tail) {
                delete _head;
                _head = _tail;
            } else {
                Node *t_node = _head->_next;
                delete _head;
                _head = t_node;
            }
            --_size;
        } else {
            // Throw exception
        }
        return data;
    }

    // Overloaded []operator definition
    template<typename T>
    T Deque<T>::operator[](int index) {
        T data;
        if (index >= 0 && index < _size) {
            Node *t_node = _head;
            while (index) {
                t_node = t_node->_next;
                --index;
            }
            data = t_node->_data;
        } else {
            // throw exception
        }

        return data;
    }

    // Overloaded ==operator definition
    template<typename T>
    bool Deque<T>::operator==(const Deque<T> &deq) {
        if (this == &deq) return true;
        if (this->_size != deq._size) return false;

        Node *t_node1 = this->_head;
        Node *t_node2 = deq._head;

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
