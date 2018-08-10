CPPFLAGS= -g

run_2darray: array2D.hpp functionality_test_2darray.cpp
	g++ $(CPPFLAGS) functionality_test_2darray.cpp -o test_2darray_exec
	valgrind ./test_2darray_exec
	rm -rf test_2darray_exec

run_dynarray: dynamicarray.hpp functionality_test_dynamicarray.cpp
	g++ $(CPPFLAGS) functionality_test_dynamicarray.cpp -o test_dynarray_exec
	valgrind ./test_dynarray_exec
	rm -rf test_dynarray_exec
