CPPFLAGS= -g -Wall -Wextra -pedantic

run_set: set.hpp functionality_test_set.cpp
	g++ $(CPPFLAGS) functionality_test_set.cpp -o test_set_exec
	valgrind ./test_set_exec
	rm -rf test_set_exec
