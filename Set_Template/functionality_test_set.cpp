#include <iostream>
#include "set.hpp"
#include "set.hpp" // Test for include guard
#include <cassert>

/*
 * Test cases for Set implementation
 */
int main() {

    // Test for insert function with duplicate entries
    nm::Set<int> set1;
    set1.insert(4);     set1.insert(0);
    set1.insert(2);     set1.insert(7);
    set1.insert(0);     set1.insert(2);
    set1.insert(6);     set1.insert(4);
    set1.insert(12);    set1.insert(11);
    set1.insert(8);     set1.insert(1);
    set1.insert(5);     set1.insert(0);
    set1.insert(3);     set1.insert(2);
    set1.insert(7);     set1.insert(1);
    set1.insert(1);     set1.insert(1);
    set1.insert(9);     set1.insert(7);
    set1.insert(11);    set1.insert(1);

    assert(set1.size() == 12);
    assert(!set1.empty());

    // Test for copy constructor uisng ==operator for comparison
    nm::Set<int> set2 = set1;
    assert(set1 == set2);

    // Test for Iterator
    std::cout << "\nElements of set after duplicate inserts ----> \t";
    for(nm::Set<int>::Iterator it = set2.begin(); it != set2.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "\n" << std::endl;
}