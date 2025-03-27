#include "Span.hpp"

void print_vector(std::vector<int> vec) {
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(6);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl; // it's not overload, but it's returning 
	return 0;
}


// int main()
// {
// 	Span sp(10);
// 	try {
// 		sp.fillingSpan(10);
// 		print_vector(sp.getVector());

// 		std::cout << sp.shortestSpan() << std::endl;
// 		std::cout << sp.longestSpan() << std::endl; // it's not overload, but it's returning 
// 	}
// 	catch ( std::exception &e) {
// 		std::cout << e.what() << std::endl;
// 	}
// 	return 0;
// }