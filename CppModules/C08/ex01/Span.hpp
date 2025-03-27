#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <exception>
#include <vector>
#include <cstdlib>
#include <ctime>

class Span {
	private:
	    unsigned int _maxSize;
		std::vector<int> _vec;

	public:
	    Span();
		Span(unsigned int n);
		Span(const Span& other);
        Span &operator=(const Span &other);
	    ~Span();

		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		void fillingSpan(unsigned int size);

		std::vector<int> getVector() const;

		// friend std::ostream& operator<<(std::ostream& os, const Span &Span);
};


#endif //
