#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>

template <typename T>
class Array {
	private:
	    T *_array; // is a  Template pointer to dynamically allocated memory
		size_t _size;

	public:
	    Array();
		Array(unsigned int n);
		Array(const Array& other);
        Array &operator=(const Array &other);
	    ~Array();
	
		T& operator[](size_t index);
		size_t size();

		class OutOfBounds : public std::exception {
			public:
				virtual const char* what() const throw() {return "Index operator[] is out of bounds.";}
			};
};

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)  {
    std::cout << "Array Default constructor called" << std::endl;
    return ;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {
    std::cout << "Array unsigned int constructor called" << std::endl;
    return ;
}

template <typename T>
Array<T>::Array(const Array &other) : _array(new T[other._size]), _size(other._size) {
    std::cout << "Array Copy constructor called" << std::endl;
    // this->array = other.array; // WRONG, this copies only the pointer
    for (size_t i = 0; i < _size; i++) {
        _array[i] = other._array[i];
    }
    return ;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
    std::cout << "Array Assignment operator called" << std::endl;
    if (this != &other) {
        delete[] _array;
        _size = other._size;
        _array = new T[_size];
        for (size_t i = 0; i < _size; ++i) {
            _array[i] = other._array[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    std::cout << "Array destructor called" << std::endl;
	delete[] _array;
    return ;
}

template <typename T>
T& Array<T>::operator[] (size_t i) {
    if (i >= _size){
        // throw std::exception("Index operator[] is out of bounds.");
		std::cout << "Exception: size " << i << "; ";
        throw OutOfBounds();
    }
    return _array[i];
}

template <typename T>
size_t Array<T>::size() {
    return _size;
}

#endif //
