#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <exception>

// template <typename T> /***MISTAKE***/
// void easyfind(T &vec, int input) { /****  it should work with any container ******/
// 	try {
// 		typename std::vector<T>::iterator i = find(vec.begin(), vec.end(), input);
// 		// std::cout << "Input: " << input << " found at index: " << (i - vec.begin())<<  std::endl;
// 	}
// 	catch (std::exception &e) {
// 		std::cout << "Exception: " << e.what() << std::endl;
// 	}
// }



template <typename T>
void easyfind(T &container, int input) {
	typename T::iterator it = find(container.begin(), container.end(), input); // find it returns the end if it doesn't find the element
	if ( it == container.end()) {
		throw std::out_of_range("Element not found");
	}
	return ;
}

// template <typename T>
// void easyfind(T &container, T input) {
// 	typename T::iterator it = find(container.begin(), container.end(), input); // find it returns the end if it doesn't find the element
// 	if ( it == container.end()) {
// 		throw std::out_of_range("Element not found");
// 	}
// 	return ;
// }

#endif // EASYFIND_HPP
