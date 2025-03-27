#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename anytype>
void iter(anytype *array, int length, void (*function)(anytype &)) {
	for (int i = 0; i < length; i++) {
		function(array[i]);
	}
}

template <typename anytype>
void function(anytype &array) {
	std::cout << array << std::endl;
}

template <typename anytype>
void iter(anytype *array, int length, void (*function)(const anytype &)) {
	for (int i = 0; i < length; i++) {
		function(array[i]);
	}
}

template <typename anytype>
void function(const anytype &array) {
	std::cout << array << std::endl;
}

#endif //
