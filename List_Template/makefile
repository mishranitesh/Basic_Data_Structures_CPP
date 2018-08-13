CPPFLAGS= -g -Wall -Wextra -pedantic

run_list: list.hpp functionality_test_list.cpp
	g++ $(CPPFLAGS) functionality_test_list.cpp -o test_list_exec
	valgrind ./test_list_exec
	rm -rf test_list_exec
