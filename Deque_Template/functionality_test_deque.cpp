#include "deque.hpp"
#include "deque.hpp" // Test for include guard
#include <iostream>
#include <cassert>

/*
 * Test cases for Deque implementation
 */
int main() {

    /*
     * Deque with integers
     */
    nm::Deque<int> d_int;

    d_int.push_back(1);
    d_int.push_back(2);
    d_int.push_back(3);
    assert(d_int.size() == 3); // Test for deque size

    d_int.push_front(4);
    d_int.push_front(5);
    assert(d_int.size() == 5); // Test for deque size

    // Print elements of Deque. [5, 4, 1, 2, 3]
    std::cout << "\nDeque elements using iterator ---> \t";
    for (auto it = d_int.begin(); it != d_int.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Test for pop_front, pop_back, size and isEmpty methods
    assert(d_int.pop_front() == 5);
    assert(d_int.pop_back() == 3);
    assert(d_int.size() == 3 && !d_int.isEmpty());

    // Test for front and back methods. [4, 1, 2]
    assert(d_int.front() == 4 && d_int.back() == 2);

    d_int.push_front(5);
    d_int.push_back(3);

    // Test for []operator. [5, 4, 1, 2, 3]
    assert(d_int[0] == 5 && d_int[4] == 3);

    /*
     * Deque with char
     */
    nm::Deque<char> d_char;

    d_char.push_back('a');
    d_char.push_back('b');
    d_char.push_back('c');
    assert(d_char.size() == 3); // Test for deque size

    d_char.push_front('d');
    d_char.push_front('e');
    assert(d_char.size() == 5); // Test for deque size

    // Print elements of Deque. [e, d, a, b, c]
    std::cout << "\nDeque elements using iterator ---> \t";
    for (auto it = d_char.begin(); it != d_char.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Test for pop_front, pop_back, size and isEmpty methods
    assert(d_char.pop_front() == 'e');
    assert(d_char.pop_back() == 'c');
    assert(d_char.size() == 3 && !d_char.isEmpty());

    // Test for front and back methods. d, a, b
    assert(d_char.front() == 'd' && d_char.back() == 'b');

    d_char.push_front('e');
    d_char.push_back('c');

    // Test for []operator. e, d, a, b, c
    assert(d_char[0] == 'e' && d_char[4] == 'c');

    /*
     * Deque with double
     */
    nm::Deque<double> d1_dbl;

    d1_dbl.push_back(1.1);
    d1_dbl.push_back(2.2);
    d1_dbl.push_back(3.3);
    d1_dbl.push_front(4.4);
    d1_dbl.push_front(5.5);

    // Print elements of Deque. [5.5, 4.4, 1.1, 2.2, 3.3]
    std::cout << "\nDeque elements using []operator ---> \t";
    for (int i = 0; i < d1_dbl.size(); ++i) {
        std::cout << d1_dbl[i] << " ";
    }
    std::cout << std::endl;

    // Test for copy constructor and assignment operator
    nm::Deque<double> d2_dbl(d1_dbl);
    nm::Deque<double> d3_dbl;
    d3_dbl = d2_dbl;

    // Test for ==operator
    assert(d1_dbl == d2_dbl);
    assert(d2_dbl == d3_dbl);

    return 0;
}