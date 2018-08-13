#include "list.hpp"
#include "list.hpp" // Test for include guard
#include <iostream>

// Custom Class to represent user defined data type
class MyClass {
    friend std::ostream &operator<<(std::ostream &os, const MyClass &obj);

public:
    MyClass(double v) : val(v) {}

private:
    double val;
};

// Overloaded output stream <<operator
std::ostream &operator<<(std::ostream &os, const MyClass &obj) {
    return os << obj.val;
}

/*
 * Test cases for List implementation
 */
int main() {

    // Must work with classes with no default ctor.
    nm::List<MyClass> list1;

    // Range based for loop [begin(), end(), != and * implementation required]
    std::cout << "\nElements of list object default ctor -----> \tEmpty" << std::endl;
    for (const auto &e : list1) {
        std::cout << e << std::endl;
    }

    // Test for push_front and range based for loop
    std::cout << "Elements of list after one push_front ----> \t";
    list1.push_front(MyClass(-1));
    for (const auto &e : list1) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // Test for erase and range based for loop
    std::cout << "Elements of list after iterator erase ----> \tEmpty" << std::endl;
    list1.erase(list1.begin());
    for (const auto &e : list1) {
        std::cout << e << std::endl;
    }

    // Test fot push_back and range based for loop
    std::cout << "Elements of list after one push_back -----> \t";
    list1.push_back(MyClass{100});
    for (const auto &e : list1) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // Append elements in list object
    list1.erase(list1.begin());
    list1.push_back(MyClass(1));
    list1.push_back(MyClass(2));
    list1.push_back(MyClass(3));
    list1.push_back(MyClass(4));
    list1.push_back(MyClass(5));
    list1.push_back(MyClass(6));
    list1.push_back(MyClass(7));
    list1.push_back(MyClass(8));
    list1.push_back(MyClass(9));

    // Iterator based for loop
    std::cout << "Elements of list with multiple entries ---> \t";
    for (auto it = list1.begin(); it != list1.end(); ++it) {
        std::cout << *it << "\t";
    }
    std::cout << std::endl;

    // Test for insert function and pre-increment and post-increment operators
    auto it1 = list1.begin();
    ++it1;
    ++it1;
    auto it2 = list1.insert(it1, MyClass(2.5)); // Inserts before the 3rd element
    *it2++ = 2.9;
    *++it2 = 4.1;
    it2++;
    list1.erase(it2);

    std::cout << "Elements of list after modification ------> \t";
    for (const auto &e : list1) {
        std::cout << e << "\t";
    }
    std::cout << "\n" << std::endl;

    return 0;
}
