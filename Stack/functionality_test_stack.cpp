#include "stack.hpp"
#include "stack.hpp" // Test for include guard
#include <iostream>
#include <cassert>

/*
 * Test cases for Stack implementation
 */
int main() {

    // Test for push function
    nm::Stack stk1;
    stk1.push(1);
    stk1.push(2);
    assert(stk1.size() == 2);

    // Test for pop function
    stk1.pop();
    stk1.pop();
    assert(stk1.size() == 0);

    // Test for peek function
    stk1.push(3);
    assert(stk1.peek() == 3);
    assert(stk1.size() == 1);

    // Test for isEmpty function
    assert(!stk1.isEmpty());
    stk1.pop();
    assert(stk1.isEmpty());

    // Test for iterator
    stk1.push(1);
    stk1.push(2);
    stk1.push(3);
    stk1.push(4);
    stk1.push(5);

    std::cout << "\nElements of stack in LIFO order ---> \t";
    for (auto it = stk1.begin(); it != stk1.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "\n" << std::endl;

    // Test for copy constructor, assignment =operator and comparison ==operator
    nm::Stack stk2{stk1};
    nm::Stack stk3;
    stk3 = stk2;

    assert(stk1 == stk2);
    assert(stk2 == stk3);

    return 0;
}