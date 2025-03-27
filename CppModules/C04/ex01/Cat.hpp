#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
	    std::string type;
		Brain	*brain;

	public:
	    Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
	    ~Cat();

		void makeSound() const; // "const override" would be more readable and useful, but it's not mandatory
		std::string getType() const;
		Brain	*getBrain(void) const;
	
};

#endif
