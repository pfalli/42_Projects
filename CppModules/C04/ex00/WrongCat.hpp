#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include <string>
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	private:
	    std::string type;

	public:
	    WrongCat();
		WrongCat(const WrongCat &other);
		WrongCat &operator=(const WrongCat &other);
	    ~WrongCat();
	
		void makeSound() const; // "const override" would be more readable and useful, but it's not mandatory
		std::string getType() const;
};

#endif //
