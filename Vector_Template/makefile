CPPFLAGS= -g -Wall -Wextra -pedantic

run_vector: vector.hpp functionality_test_vector.cpp
	g++ $(CPPFLAGS) functionality_test_vector.cpp -o test_vector_exec
	valgrind ./test_vector_exec
	rm -rf test_vector_exec
