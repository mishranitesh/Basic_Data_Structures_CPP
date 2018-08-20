#include "vector.hpp"
#include "vector.hpp" // Test for include guard
#include <iostream>
#include <cassert>
#include <vector>

/*
 * Test cases for Vector implementation
 */
int main() {

    /*
     * TEST CASES with nm::Vector class implementation
     */
    std::cout << "\n-------------------------------------------------------------------------------------------------------------\n" << std::endl;
    std::cout << "#################### TEST OUTPUT using nm::Vector<?> ####################\n" << std::endl;
	nm::Vector<int> vec1;
    nm::Vector<int>::Iterator it;
    nm::Vector<int>::ReverseIterator rit;

    // Test for push_back
    for (int i = 1; i <= 5; i++) {
        vec1.push_back(i);
    }

    // Test for begin and end
    std::cout << "Vector integer elements using iterator -----------> \t";
    for (it = vec1.begin(); it != vec1.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    // Test for rbegin and rend
    std::cout << "Vector integer elements using reverse iterator ---> \t";
    for (rit = vec1.rbegin(); rit != vec1.rend(); ++rit) {
        std::cout << *rit << ' ';
    }
    std::cout << "\n" << std::endl;

    // Test for size and empty
    assert(vec1.size() == 5);
    assert(!vec1.empty());

    // Test using another data type - double
    nm::Vector<double> vec2;
    nm::Vector<double>::Iterator it2;

    // Test for push_back
    for (int i = 1; i <= 10; i++) {
        vec2.push_back(i * 10.1);
    }

    // Test for begin and end
    std::cout << "Vector double elements using iterator ------------> \t";
    for (it2 = vec2.begin(); it2 != vec2.end(); ++it2) {
        std::cout << *it2 << "  ";
    }
    std::cout << std::endl;

    // Test for reference []operator, at, front and back functions
    std::cout << "Reference []operator => vector[2] ----------------> \t" << vec2[2] << std::endl;
    std::cout << "Function at() ========> vector.at(4) -------------> \t" << vec2.at(4) << std::endl;
    std::cout << "Function front() =====> vector.front() -----------> \t" << vec2.front() << std::endl;
    std::cout << "Function back() ======> vector.back() ------------> \t" << vec2.back() << std::endl;

    std::cout << "\n\n-------------------------------------------------------------------------------------------------------------\n" << std::endl;


    /*
     * SAME TEST CASES with standard std::vector class
     */
    std::cout << "\n#################### TEST OUTPUT using std::vector<?> ####################\n" << std::endl;

    // Standard Vector
    std::vector<int> s_vec1;
    std::vector<int>::iterator it_s;
    std::vector<int>::reverse_iterator rit_s;

    // Test for push_back
    for (int i = 1; i <= 5; i++) {
        s_vec1.push_back(i);
    }

    // Test for begin and end
    std::cout << "Vector integer elements using iterator -----------> \t";
    for (it_s = s_vec1.begin(); it_s != s_vec1.end(); ++it_s) {
        std::cout << *it_s << ' ';
    }
    std::cout << std::endl;

    // Test for rbegin and rend
    std::cout << "Vector integer elements using reverse iterator ---> \t";
    for (rit_s = s_vec1.rbegin(); rit_s != s_vec1.rend(); ++rit_s) {
        std::cout << *rit_s << ' ';
    }
    std::cout << "\n" << std::endl;

    // Test for size and empty
    assert(s_vec1.size() == 5);
    assert(!s_vec1.empty());

    // Test using another data type - double
    std::vector<double> s_vec2;
    std::vector<double>::iterator it_d;

    // Test for push_back
    for (int i = 1; i <= 10; i++) {
        s_vec2.push_back(i * 10.1);
    }

    // Test for begin and end
    std::cout << "Vector double elements using iterator ------------> \t";
    for (it_d = s_vec2.begin(); it_d != s_vec2.end(); ++it_d) {
        std::cout << *it_d << "  ";
    }
    std::cout << std::endl;

    // Test for reference []operator, at, front and back functions
    std::cout << "Reference []operator => vector[2] ----------------> \t" << s_vec2[2] << std::endl;
    std::cout << "Function at() ========> vector.at(4) -------------> \t" << s_vec2.at(4) << std::endl;
    std::cout << "Function front() =====> vector.front() -----------> \t" << s_vec2.front() << std::endl;
    std::cout << "Function back() ======> vector.back() ------------> \t" << s_vec2.back() << std::endl;
    std::cout << "\n\n-------------------------------------------------------------------------------------------------------------\n" << std::endl;

    return 0;
}
