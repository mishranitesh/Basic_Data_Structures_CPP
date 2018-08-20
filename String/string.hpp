#ifndef NITESH_STRING_H
#define NITESH_STRING_H

#include<iostream>
#include <cstring>

/*
 * Namespace to contain implementation of Stack Data Structure
 */
namespace nm {

    /*
     * Class to represent String and contains implementation
     */
    class String {
    public:

        // Public friend free function
        friend std::ostream &operator<<(std::ostream &os, const String &str);

        // Contructors, Assignment Operator and Destructor
        String();                               // Default ctor
        String(const char *buf);                // Value ctor
        String(const String &str);              // Copy ctor
        ~String();                              // Dtor
        String &operator=(const String &str);   // Assignment =operator
        bool operator==(const String &str);     // Operator ==overloading
        String &operator+(const String &str);   // Operator +overloading

    private:
        // Private Member Variables
        char *_buf;
        std::size_t _length;
    };

    // Default constructor definition
    String::String() {
        _length = 0;
        _buf = new char[1];
        _buf[0] = '\0';
    }

    // Value constructor definition
    String::String(const char *buf) {
        _length = strlen(buf);
        _buf = new char[_length + 1];
        strcpy(_buf, buf);
    }

    // Copy constructor definition
    String::String(const String &str) {
        _length = strlen(str._buf);
        _buf = new char[_length + 1];
        strcpy(_buf, str._buf);
    }

    // Destructor definition
    String::~String() {
        delete[] _buf;
    }

    // Assignment =operator definition
    String &String::operator=(const String &str) {

        // Self-assignment check
        if (this == &str) {
            return *this;
        }

        // Delete old data
        delete[] _buf;
        _length = 0;

        // Copy new data
        _length = strlen(str._buf);
        _buf = new char[_length + 1];
        strcpy(_buf, str._buf);

        return *this;
    }

    // Overloaded <<operator definition
    std::ostream &operator<<(std::ostream &os, const String &str) {
        os << "String = " << str._buf << " and Length = " << str._length;
        return os;
    }

    // Overloaded ==operator definition
    bool String::operator==(const String &str) {
        if (str._length != this->_length) {
            return false;
        }

        for (std::size_t i = 0; i < str._length; ++i) {
            if (str._buf[i] != this->_buf[i]) {
                return false;
            }
        }

        return true;
    }

    // Overloaded +operator definition
    String &String::operator+(const String &str) {
        auto *temp_buf = new char[strlen(_buf) + 1];
        strcpy(temp_buf, _buf);

        delete[] _buf;

        _length += str._length;
        _buf = new char[_length + 1];
        strcpy(_buf, temp_buf);
        strcat(_buf, str._buf);
        delete[] temp_buf;

        return *this;
    }
}

#endif
