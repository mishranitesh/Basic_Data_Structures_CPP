#ifndef NITESH_DYNAMICARR_HPP
#define NITESH_DYNAMICARR_HPP

#include <iostream>

namespace nm {

    /*
     * Class to represent Dynamic Array and contains its implementation
     */
    class DynamicArray {
    public:
        friend std::ostream &operator<<(std::ostream &os, const DynamicArray &darr);

        /*
         * Constructor, Assignment Operator and Destructor
         */
        DynamicArray(int size = 0);             // Default argument ctor
        DynamicArray(const DynamicArray &);     // Copy ctor
        ~DynamicArray();                        // Default dtor
        DynamicArray &operator=(const DynamicArray &) = delete; // Assignment operator

        /*
         * Overloaded Operators
         */
        DynamicArray &operator[](int index);        // Operator[] overloading
        bool operator==(const DynamicArray &);      // Operator== overloading
        bool operator!=(const DynamicArray &);      // Operator!= overloading
        void operator=(int value);                  // Operator= overloading

        /*
         * Member Function Declaration
         */
        void insert(int, int);
        int length() { return _size; }

        /*
         * Inner class to represent Iterator
         */
        class Iterator {
        public:
            Iterator() = default;
            Iterator(int *arr, int index) : _iter_arr{arr}, _iter_index{index} {}
            ~Iterator() = default;

            // Pre increment
            Iterator &operator++() {
                ++_iter_index;
                return *this;
            }

            // Post increment
            Iterator operator++(int) {
                Iterator temp_iter{this->_iter_arr, this->_iter_index};
                ++_iter_index;
                return temp_iter;
            }

            // Dereference operator
            int &operator*() const {
                return this->_iter_arr[_iter_index];
            }

            // Getter method
            int get_iter_index() const { return _iter_index; }

        private:
            int _iter_index;
            int *_iter_arr;
        };

        Iterator begin() { return Iterator{this->_arr, 0}; }

        Iterator end() { return Iterator{this->_arr, _size}; }

        friend bool operator!=(const Iterator &iter_1, const Iterator &iter_2) {
            return (iter_1.get_iter_index() != iter_2.get_iter_index());
        }

    private:
        int _size;
        int *_arr;
        int _index;
    };

    // Value ctor definition
    DynamicArray::DynamicArray(int size) : _size{size}, _index{-1} {
        if (size) {
            _arr = new int[size];
            for (int i = 0; i < size; ++i) {
                _arr[i] = -9999; // Default value as array element
            }
        } else {
            _arr = nullptr;
        }
    }

    // Destructor definition
    DynamicArray::~DynamicArray() {
        delete[] _arr;
    }

    // Copy ctor definition
    DynamicArray::DynamicArray(const DynamicArray &darr) : _index{-1} {
        _size = darr._size;
        _arr = new int[_size];
        for (int i = 0; i < _size; ++i) {
            _arr[i] = darr._arr[i];
        }
    }

    // Insert function definition
    void DynamicArray::insert(int index, int value) {
        if (index < _size) {
            _arr[index] = value;
        }
    }

    // Overloaded []operator definition
    DynamicArray &DynamicArray::operator[](int index) {
        if (index < _size) {
            _index = index;
        } else {
            _index = -1;
        }
        return *this;
    }

    // Overloaded =operator definition
    void DynamicArray::operator=(int value) {
        if (_index != -1) {
            _arr[_index] = value;
            _index = -1;
        } else {
            // throw exceptions
        }
    }

    // Overloaded ==operator definition
    bool DynamicArray::operator==(const DynamicArray &darr) {
        if (this->_size != darr._size) {
            return false;
        }
        for (int i = 0; i < this->_size; ++i) {
            if (this->_arr[i] != darr._arr[i]) {
                return false;
            }
        }
        return true;
    }

    // Overloaded !=operator definition
    bool DynamicArray::operator!=(const DynamicArray &darr) {
        return !(*this == darr);
    }

    // Overloaded <<operator definition
    std::ostream &operator<<(std::ostream &os, const DynamicArray &darr) {
        if (darr._index != -1) {
            os << darr._arr[darr._index];
        } else {
            // throw exceptions
        }
        return os;
    }
}

#endif