#ifndef NITESH_ARRAY_HPP
#define NITESH_ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <string>

namespace nm {

    /*
     * Class to represent 2D Array and contains basic implementation
     */
    class Array2D {
    public:
        friend std::ostream &operator<<(std::ostream &, const Array2D &); // Operator << overloading

        /*
         * Constructor, Destructor and Assignment Operator
         */
        Array2D() = delete;                     // Default ctor
        Array2D(const Array2D &);               // Copy ctor
        ~Array2D();                             // Default Dtor
        Array2D &operator=(const Array2D &);    // Assignment operator
        Array2D(size_t, size_t);                // Value ctor

        /*
         * Overloaded methods
         */
        Array2D &operator[](size_t);        // Operator [] overloading
        void operator=(size_t);             // Operator = overloading
        bool operator==(const Array2D &);   // Operator == overloading

        // Getter methods - Inline
        size_t rows() { return _row; }
        size_t columns() { return _column; }

        /*
         * Inner Class to represent Row Out of Range Exception
         */
        class RowOutOfRangeException {
        public:
            RowOutOfRangeException(const std::string &&msg) : _msg{msg} {}
            ~RowOutOfRangeException() = default;
            std::string getMessage() const { return _msg; }

        private:
            std::string _msg;
        };

        /*
         * Inner Class to represent Column Out of Range Exception
         */
        class ColumnOutOfRangeException {
        public:
            ColumnOutOfRangeException(const std::string &&msg) : _msg{msg} {}
            ~ColumnOutOfRangeException() = default;
            std::string getMessage() const { return _msg; }

        private:
            std::string _msg;
        };

        /*
         * Inner class to represent Iterator
         */
        class Iterator {
        public:
            Iterator(int **val, size_t row, size_t col) : _iter_values{val}, _iter_r{row}, _iter_c{col} {}
            Iterator &operator=(const Iterator &) = delete;
            ~Iterator() {
                for (int i = 0; i < _new_row; ++i) {
                    delete[] _iter_values[i];
                }
                delete[] _iter_values;
            }

            // Pre increment operator
            Iterator &operator++() {
                ++_iter_c;
                if (_iter_c == _new_col) {
                    _iter_c = 0;
                    ++_iter_r;
                }
                return *this;
            }

            // Post increment operator
            Iterator operator++(int) {
                Iterator temp_iter{this->_iter_values, this->_iter_r, this->_iter_c};
                ++_iter_c;
                if (_iter_c == _new_col) {
                    _iter_c = 0;
                    ++_iter_r;
                }
                return temp_iter;
            }

            // Dereference operator
            const int &operator*() const {
                return this->_iter_values[_iter_r][_iter_c];
            }

            size_t get_iter_r() const { return _iter_r; }
            size_t get_iter_c() const { return _iter_c; }

            // Static member variables
            static size_t _new_row;
            static size_t _new_col;

        private:
            int **_iter_values;
            size_t _iter_r;
            size_t _iter_c;
        };

        // Function to return Iterator object with begin pointer (Column Major Order)
        Iterator cmbegin() {
            Iterator::_new_row = _column;
            Iterator::_new_col = _row;
            int **new_values = new int *[Iterator::_new_row];
            for (int i = 0; i < Iterator::_new_row; ++i) {
                new_values[i] = new int[Iterator::_new_col];
            }
            int r = 0;
            int c = 0;
            for (int i = 0; i < _column; ++i) {
                for (int j = 0; j < _row; ++j) {
                    new_values[r][c] = _values[j][i];
                    c++;
                }
                r++;
                c = 0;
            }
            return Iterator{new_values, 0, 0};
        }

        // Function to return Iterator object with end pointer (Column Major Order)
        Iterator cmend() {
            Iterator::_new_row = _column;
            Iterator::_new_col = _row;
            int **new_values = new int *[Iterator::_new_row];
            for (int i = 0; i < Iterator::_new_row; ++i) {
                new_values[i] = new int[Iterator::_new_col];
            }
            int r = 0;
            int c = 0;
            for (int i = 0; i < _column; ++i) {
                for (int j = 0; j < _row; ++j) {
                    new_values[r][c] = _values[j][i];
                    c++;
                }
                r++;
                c = 0;
            }
            return Iterator{new_values, _column, _row};
        };

        // Function to compare two iterators
        friend bool operator==(const Iterator &iter_1, const Iterator &iter_2) {
            return (iter_1.get_iter_r() == iter_2.get_iter_r());
        }

        friend bool operator!=(const Iterator &iter_1, const Iterator &iter_2) {
            return (iter_1.get_iter_r() != iter_2.get_iter_r());
        }

    private:
        size_t _row;
        size_t _column;
        int **_values;
        size_t _r;
        size_t _c;
        static int _loop;
    };

    // Static member initialization
    int Array2D::_loop = 0;
    size_t Array2D::Iterator::_new_row = 0;
    size_t Array2D::Iterator::_new_col = 0;

    // Value ctor definition
    Array2D::Array2D(size_t row, size_t col) : _row{row}, _column{col} {
        _values = new int *[_row];
        for (int i = 0; i < _row; ++i) {
            _values[i] = new int[_column];
        }
        _loop = 0;
        _r = -1;
        _c = -1;
    }

    // Copy ctor definition
    Array2D::Array2D(const Array2D &arr) {
        _row = arr._row;
        _column = arr._column;
        _values = new int *[_row];
        for (int i = 0; i < _row; ++i) {
            _values[i] = new int[_column];
        }
        _loop = 0;
        _r = -1;
        _c = -1;

        // Copying the elements
        for (int i = 0; i < _row; ++i) {
            for (int j = 0; j < _column; ++j) {
                _values[i][j] = arr._values[i][j];
            }
        }
    }

    // Assignment operator definition
    Array2D &Array2D::operator=(const Array2D &arr) {
        // Self-assignment check
        if (this == &arr) { return *this; }

        // Delete the old array
        for (int i = 0; i < _row; ++i) {
            delete[] _values[i];
        }
        delete[] _values;

        // Reinitialization
        _row = arr._row;
        _column = arr._column;
        _values = new int *[_row];
        for (int i = 0; i < _row; ++i) {
            _values[i] = new int[_column];
        }
        _loop = 0;
        _r = -1;
        _c = -1;

        // Copying the elements
        for (int i = 0; i < _row; ++i) {
            for (int j = 0; j < _column; ++j) {
                _values[i][j] = arr._values[i][j];
            }
        }
    }

    // Destructor definition
    Array2D::~Array2D() {
        for (int i = 0; i < _row; ++i) {
            delete[] _values[i];
        }
        delete[] _values;
    }

    // Overloaded []operator definition
    Array2D &Array2D::operator[](size_t index) {
        if (_loop == 0) {
            if (index < _row) {
                _r = index;
                ++_loop;
            } else {
                throw (RowOutOfRangeException("Row Out of Range Exception."));
            }
            return *this;
        }

        if (_loop == 1) {
            if (index < _column) {
                _c = index;
                _loop = 0;
            } else {
                throw (ColumnOutOfRangeException("Column Out of Range Exception."));
            }
            return *this;
        }
    }

    // Overloaded =operator definition
    void Array2D::operator=(size_t value) {
        if (_r != -1 && _c != -1) {
            _values[_r][_c] = value;
            _r = -1;
            _c = -1;
            _loop = 0;
        }
    }

    // Overloaded ==operator definition
    bool Array2D::operator==(const Array2D &arr) {
        if (this == &arr) {
            return true;
        }

        if (_values[_r][_c] != arr._values[_r][_c]) {
            return false;
        }

        return true;
    }

    // Overloaded <<operator definition
    std::ostream &operator<<(std::ostream &os, const Array2D &arr) {
        os << arr._values[arr._r][arr._c];
        return os;
    }
}

#endif