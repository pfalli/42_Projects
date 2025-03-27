#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
    return ;
}

Dog::Dog(const Dog &other) : Animal(other){{
    std::cout << "Copy constructor called" << std::endl;
    this->type = other.type;
    return ;
}}


Dog &Dog::operator=(const Dog &other) {{
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        this->type = other.type;
    }
    return *this;
}}


Dog::~Dog() {
    std::cout << "Dog deconstructor called" << std::endl;
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