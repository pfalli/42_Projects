#include "Animal.hpp"

Animal::Animal() {
    this->type = "Generic Animal";
    std::cout << "Animal constructor called" << std::endl;
    return ;
}

Animal::Animal(const Animal &other) {{
    std::cout << "Copy constructor called" << std::endl;
    this->type = other.type;
    return ;
}}


Animal &Animal::operator=(const Animal &other) {{
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
    return ;
}

//-----------------------------------------------------
//               FUNCTIONS
//----------------------------------------------------


void Animal::makeSound() const {
    std::cout << "Animals make sounds!" << std::endl;
}

std::string Animal::getType() const {
    return (this->type);
}