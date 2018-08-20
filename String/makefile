CPPFLAGS= -g -Wall -Wextra -pedantic

run_string: string.hpp functionality_test_string.cpp
	g++ $(CPPFLAGS) functionality_test_string.cpp -o test_string_exec
	valgrind ./test_string_exec
	rm -rf test_string_exec
