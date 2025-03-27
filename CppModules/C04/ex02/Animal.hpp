#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

//Function Overriding with Virtual Functions
/* Derived classes can override functions of the base class. When a pointer or reference 
to a base class points to a derived class object, the function of the derived class is called 
if the base class function is declared virtual */

class Animal {
	protected:
		std::string type;

	public:
		Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
	    virtual ~Animal();

		virtual void makeSound() const = 0; // Pure virtual function. Since it's 0 it cannot be instantiated directly, but from the derived classes
        virtual std::string getType() const;
};

#endif //
