#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() : Animal() {
    this->type = "Cat";
    std::cout << "Cat  default constructor called" << std::endl;
    return ;
}

Cat::Cat(const Cat &other) : Animal(other) {{
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = other.type;
    return ;
}}


Cat &Cat::operator=(const Cat &other) {{
    std::cout << "Cat Assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
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