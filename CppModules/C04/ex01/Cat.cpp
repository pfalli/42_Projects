#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal() {
    this->type = "Cat";
    this->brain = new Brain;
    std::cout << "Cat  default constructor called" << std::endl;
    return ;
}

Cat::Cat(const Cat &other) : Animal(other) {{
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain);
    return ;
}}


Cat &Cat::operator=(const Cat &other) {{
    std::cout << "Cat Assignment operator called" << std::endl;
    if (this->brain)
        delete this->brain;
    this->brain = new Brain(*other.brain);
    this->type = other.type;
    return *this;
}}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
    return ;
}

//-----------------------------------------------------
//               FUNCTIONS
//----------------------------------------------------

void Cat::makeSound() const {
    std::cout << "Miaw 🐱" << std::endl;
}

std::string Cat::getType() const {
    return (this->type);
}

Brain*	Cat::getBrain(void) const
{
	return (this->brain);
}