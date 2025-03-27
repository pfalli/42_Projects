#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    this->type = "Bird";
    std::cout << "WrongCat constructor called" << std::endl;
    return ;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {{
    std::cout << "Copy constructor called" << std::endl;
    this->type = other.type;
    return ;
}}


WrongCat &WrongCat::operator=(const WrongCat &other) {{
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}}

WrongCat::~WrongCat() {
    std::cout << "WrongCat deconstructor called" << std::endl;
    return ;
}

//-----------------------------------------------------
//               FUNCTIONS
//----------------------------------------------------

void WrongCat::makeSound() const {
    std::cout << "Chip chip 🐤" << std::endl;
}

std::string WrongCat::getType() const {
    return (this->type);
}