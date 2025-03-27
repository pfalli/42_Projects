#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->type = "Dog";
    this->brain = new Brain;
    std::cout << "Dog constructor called" << std::endl;
    return ;
}

Dog::Dog(const Dog &other) : Animal(other){{
    std::cout << "Dog Copy constructor called" << std::endl;
	this->type = other.type;
    this->brain = new Brain(*other.brain);
    return ;
}}


Dog &Dog::operator=(const Dog &other) {{
    std::cout << "Dog Assignment operator called" << std::endl;
    if (this->brain)
        delete this->brain;
    this->brain = new Brain(*other.brain);
    this->type = other.type;
    return *this;
}}


Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
    return ;
}

//-----------------------------------------------------
//               FUNCTIONS
//----------------------------------------------------

void Dog::makeSound() const {
    std::cout << "Bau 🐶" << std::endl;
}

std::string Dog::getType() const {
    return (this->type);
}

Brain*	Dog::getBrain(void) const
{
	return (this->brain);
}