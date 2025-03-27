#include "Span.hpp"

Span::Span() : _maxSize(0) {
    std::cout << "Span Default constructor called" << std::endl;
    return ;
}

Span::Span(unsigned int n) : _maxSize(n) {
    std::cout << "Span int constructor called" << std::endl;
    return ;
}

Span::Span(const Span &other) :  _maxSize(other._maxSize), _vec(other._vec) {
    std::cout << "Span Copy constructor called" << std::endl;
    return ;
}

Span &Span::operator=(const Span &other) {
    std::cout << "Span Assignment operator called" << std::endl;
    if (this != &other) {
        _maxSize = other._maxSize;
        _vec = other._vec;
    }
    return (*this);
}

Span::~Span() {
    std::cout << "Span Default destructor called" << std::endl;
    return ;
}

//-----------------------------------------------------
//               FUNCTIONS
//----------------------------------------------------


void Span::addNumber(int num) {
    if ( _maxSize > _vec.size()) {
        _vec.push_back(num); // or emplace_back()
    }
    else
        throw std::out_of_range("Exception: Out of bounds");
}

int Span::shortestSpan() {
    if (_vec.size() < 2) {
        throw std::out_of_range("Exception: Not enough elements in container");
    }
    std::vector<int>temp = _vec; // so the original is not modified by std::sort
    std::sort(temp.begin(), temp.end());
    int min = temp[1] - temp[0];
    for (size_t i = 2; i < _vec.size(); i++) {
        if (temp[i] - temp [i - 1] < min) {
            min = temp[i] - temp [i - 1];
        }
    }
    return min;
}

int Span::longestSpan() {
    if (_vec.size() < 2) {
        throw std::out_of_range("Exception: Not enough elements in container");
    }
    int max = *std::max_element(this->_vec.begin(), this->_vec.end());
    int min = *std::min_element(this->_vec.begin(), this->_vec.end());
    return max - min;
}

void Span::fillingSpan(unsigned int size) {
    std::srand(static_cast<unsigned int>(time(0)));
    if (size > _maxSize) {
        throw std::out_of_range("Too many element for the vector.");
    }
    for (unsigned int i = 0; i < size; i++) {
        int random_num = rand() % 100 + 1;
        // std::cout << random_num << " ";
        _vec.push_back(random_num);
    }
}


std::vector<int> Span::getVector() const {
    return _vec;
}
