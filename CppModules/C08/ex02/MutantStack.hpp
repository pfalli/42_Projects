#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <exception>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T> { // Wrapper Class
	public:
	    MutantStack();
		MutantStack(const MutantStack& other);
        MutantStack &operator=(const MutantStack &other);
	    ~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    	// iterator begin() { return this->c.begin(); }
    	// iterator end() { return this->c.end(); }
        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;

};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(){
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(){
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const{
	return this->c.end();
}


template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
    std::cout << "MutantStack Default constructor called" << std::endl;
    return ;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other)  {
    std::cout << "MutantStack Copy constructor called" << std::endl;
    (void) other;
    return ;
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other) {
    std::cout << "MutantStack Assignment operator called" << std::endl;
    if (this != &other) {
        std::stack<T>::operator=(other);
    }
    return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack() {
    std::cout << "MutantStack Default destructor called" << std::endl;
    return ;
}


#endif // MUTANTSTACK_HPP
