#include "string.hpp"
#include "string.hpp" // Test for include guard
#include <cassert>

/*
 * Test cases for Stack implementation
 */
int main() {

	using nm::String;

	// Test for Value constructors
	String str1("Nitesh");
	String str2 = "Mishra";
	assert(str1 == String("Nitesh"));
	assert(str2 == String("Mishra"));

	// Test for Copy constructors
	String str3 = String("String Test Case");
	String str4 = str1;
	assert(str4 == str1);

	// Test for Assignment operator
	str4 = str3;
	assert(str3 == str4);

	// Test for Overloaded <<operator
	std::cout << str1 << "\n" << str2 << std::endl;
	std::cout << str3 << std::endl;

	// Test for allocating heap memory
	auto *str_ptr = new String("String in Heap");
	std::cout << *str_ptr << std::endl;
	delete str_ptr;

	// Test for Overloaded +operator
	String ss1("Hello");
	String ss2 = "World !!";
	String ss3 = ss1 + " " + ss2;
	assert(ss3 == String("Hello World !!"));

	return 0;
}
