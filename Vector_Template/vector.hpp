#ifndef NITESH_VECTOR_HPP
#define NITESH_VECTOR_HPP

/*
 * Namespace to contain implementation of Vector Data Structure
 */
namespace nm {

    /*
     * Template Class to represent Vector and contains implementation
     */
    template<typename T>
    class Vector {
    public:

        // Contructors, Assignment Operator and Destructor
        Vector();
        Vector(const Vector &) = default;
        Vector &operator=(const Vector &) = default;
        ~Vector() { delete[] _arr; }

        // Public Member Functions
        void push_back(T);
        T operator[](int);
        T at(int);
        T front();
        T back();

        // Public Inline Member Functions
        bool empty() { return (_size == 0); }
        int size() { return _size; }

        /*
         * Inner class to represent iterator
         */
        class Iterator {
        public:

            // Constructors and Destructor
            Iterator() : _iter_arr{0}, _iter_index{-1} {}
            Iterator(T *arr, int index) : _iter_arr{arr}, _iter_index{index} {}

            Iterator(const Iterator &iter) {
                _iter_arr = iter._iter_arr;
                _iter_index = iter._iter_index;
            }
            ~Iterator() = default;

            // Assignment Operator
            Iterator &operator=(const Iterator &iter) {
                if (this == &iter) return *this;
                _iter_arr = iter._iter_arr;
                _iter_index = iter._iter_index;
                return *this;
            }

            // Pre increment operator
            Iterator &operator++() {
                ++_iter_index;
                return *this;
            }

            // Post increment operator
            Iterator operator++(int) {
                Iterator temp_iter{this->_iter_arr, this->_iter_index};
                ++_iter_index;
                return temp_iter;
            }

            // Dereference operator
            T operator*() const {
                return this->_iter_arr[_iter_index];
            }

            // Public getter function
            int get_iter_index() const { return _iter_index; }

        private:
            T *_iter_arr;
            int _iter_index;
        };

        /*
         * Inner class to represent reverse iterator
         */
        class ReverseIterator {
        public:

            // Constructors and Destructor
            ReverseIterator() : _riter_arr{nullptr}, _riter_index{-1} {}
            ReverseIterator(T *arr, int index) : _riter_arr{arr}, _riter_index{index} {}
            ReverseIterator(const ReverseIterator &iter) {
                _riter_arr = iter._riter_arr;
                _riter_index = iter._riter_index;
            }
            ~ReverseIterator() = default;

            // Assignment Operator
            ReverseIterator &operator=(const ReverseIterator &iter) {
                if (this == &iter) return *this;
                _riter_arr = iter._riter_arr;
                _riter_index = iter._riter_index;
                return *this;
            }

            // Pre increment operator
            ReverseIterator &operator++() {
                --_riter_index;
                return *this;
            }

            // Post increment operator
            ReverseIterator operator++(int) {
                ReverseIterator temp_iter{this->_riter_arr, this->_riter_index};
                --_riter_index;
                return temp_iter;
            }

            // Dereference operator
            T operator*() const {
                return this->_riter_arr[_riter_index];
            }

            // Public getter function
            int get_riter_index() const { return _riter_index; }

        private:
            T *_riter_arr;
            int _riter_index;
        };

        // Public Member Functions
        Iterator begin() {
            return Iterator{_arr, 0};
        }

        Iterator end() {
            return Iterator{_arr, _size};
        }

        ReverseIterator rbegin() {
            return ReverseIterator{_arr, _size - 1};
        }

        ReverseIterator rend() {
            return ReverseIterator{_arr, -1};
        }

        // Public friend functions
        friend bool operator!=(const Iterator &iter_1, const Iterator &iter_2) {
            return (iter_1.get_iter_index() != iter_2.get_iter_index());
        }

        friend bool operator!=(const ReverseIterator &iter_1, const ReverseIterator &iter_2) {
            return (iter_1.get_riter_index() != iter_2.get_riter_index());
        }

    private:
        // Private member variables
        int _size;
        T *_arr;
        int _index;
        int _capacity;
    };

    // Default ctor definition
    template<typename T>
    Vector<T>::Vector() : _size{0}, _arr{0}, _index{-1}, _capacity{4} {
        _arr = new T[_capacity];
        for (int i = 0; i < _capacity; ++i) {
            _arr[i] = 0;
        }
    }

    // Push back function definition
    template<typename T>
    void Vector<T>::push_back(T data) {
        if (_size == _capacity) {
            _capacity *= 2;
            T *n_arr = new T[_capacity];
            for (int i = 0; i < _size; ++i) {
                n_arr[i] = _arr[i];
            }
            delete[] _arr;
            _arr = n_arr;
        }
        ++_index;
        _arr[_index] = data;
        ++_size;

        return;
    }

    // Overloaded []operator definition
    template<typename T>
    T Vector<T>::operator[](int index) {
        if (index >= _size) {
            // throw exception
        }
        return _arr[index];
    }

    // At function definition
    template<typename T>
    T Vector<T>::at(int index) {
        if (index >= _size) {
            // throw exception
        }
        return _arr[index];
    }

    // Front function definition
    template<typename T>
    T Vector<T>::front() {
        return _arr[0];
    }

    // Back function definition
    template<typename T>
    T Vector<T>::back() {
        return _arr[_size - 1];
    }
}

#endif