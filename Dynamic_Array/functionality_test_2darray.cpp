#include "array2D.hpp"
#include "array2D.hpp" // Test include guards
#include <cstddef>
#include <iostream>
#include <cassert>
#include <typeinfo>

/*
 * Test cases for 2D Array implementation
 */
int main() {

    /*
     * Test for Constructor
     */
    nm::Array2D arr1{2, 3};
    assert(typeid(arr1.rows()) == typeid(std::size_t));
    assert(typeid(arr1.columns()) == typeid(std::size_t));

    /*
     * Test for Indexing
     */
    for (std::size_t i = 0; i < arr1.rows(); i++) {
        for (std::size_t j = 0; j < arr1.columns(); j++) {
            arr1[i][j] = i * arr1.columns() + j;
        }
    }

    // Printing the array in Row Major Order
    std::cout << "\nArray elements in Row Major Order --> \t\t";
    for (std::size_t i = 0; i < arr1.rows(); i++) {
        for (std::size_t j = 0; j < arr1.columns(); j++) {
            std::cout << arr1[i][j] << " ";
        }
    }
    std::cout << "\n" << std::endl;

    /*
     * Test for Range Checking
     */
    try {
        arr1[2][1];
        assert(false);
    } catch (const nm::Array2D::RowOutOfRangeException &ex) {
        std::cout << ex.getMessage() << std::endl;
    }

    try {
        arr1[1][3];
        assert(false);
    } catch (const nm::Array2D::ColumnOutOfRangeException &ex) {
        std::cout << ex.getMessage() << "\n" << std::endl;
    }

    /*
     * Test for Copy Constructor
     */
    nm::Array2D arr2{arr1};
    // Verify.
    for (std::size_t i = 0; i < arr1.rows(); i++) {
        for (std::size_t j = 0; j < arr1.columns(); j++) {
            assert(arr2[i][j] == arr1[i][j]);
        }
    }

    /*
     * Test for Assignment Operator
     */
    nm::Array2D arr3{1, 1};
    arr3 = arr2;
    // Verify.
    for (std::size_t i = 0; i < arr3.rows(); i++) {
        for (std::size_t j = 0; j < arr3.columns(); j++) {
            assert(arr3[i][j] == arr2[i][j]);
        }
    }

    /*
     * Test for Column Major Iterator
     */
    std::cout << "Array elements in Column Major Order --> \t";
    for (auto it = arr1.cmbegin(); it != arr1.cmend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n" << std::endl;
}
