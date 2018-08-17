CPPFLAGS= -g -Wall -Wextra -pedantic

run_stack: stack.hpp functionality_test_stack.cpp
	g++ $(CPPFLAGS) functionality_test_stack.cpp -o test_stack_exec
	valgrind ./test_stack_exec
	rm -rf test_stack_exec
