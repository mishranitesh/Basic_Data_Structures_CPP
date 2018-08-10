CPPFLAGS= -g -Wall -Wextra -pedantic

run_deque: deque.hpp functionality_test_deque.cpp
	g++ $(CPPFLAGS) functionality_test_deque.cpp -o test_deque_exec
	valgrind ./test_deque_exec
	rm -rf test_deque_exec
