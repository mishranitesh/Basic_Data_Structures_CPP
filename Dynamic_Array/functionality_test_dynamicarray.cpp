#include "dynamicarray.hpp"
#include "dynamicarray.hpp" // Test for include guards
#include <cassert>

/*
 * Test cases for Dynamic Array implementation
 */
int main(int argc, char **argv) {

    /*
     * Test for Dynamic 1D Array
     */
    nm::DynamicArray arr1 = nm::DynamicArray(4);

    // Array initialization using insert and [] operator
    arr1.insert(0, 9);
    arr1.insert(1, 7);
    arr1.insert(3, 2);
    arr1[2] = 4;

    // Invalid index -- NOOP
    arr1[10] = 5;

    // Test for []operator
    std::cout << "\nArray elements using [] operator --> \t";
    for (int i = 0; i < arr1.length(); ++i) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    // Test for iterator
    std::cout << "Array elements using iterator --> \t";
    for (auto it = arr1.begin(); it != arr1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n" << std::endl;

    // Test for ==operator
    nm::DynamicArray arr2 = nm::DynamicArray(arr1);
    assert(arr1 == arr2);

    // Test for !=operator
    arr1[1] = 9999111;
    assert(arr1 != arr2);

    // Test for array elements comparison
    arr1[1] = 7;
    for (auto it1 = arr1.begin(), it2 = arr2.begin(); it1 != arr1.end() && it2 != arr2.end(); ++it1, ++it2) {
        assert(*it1 == *it2);
    }

    return 0;
}