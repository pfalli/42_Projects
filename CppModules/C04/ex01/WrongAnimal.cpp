#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    this->type = "WrongAnimal";
    std::cout << "WrongAnimal constructor called" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {{
    std::cout << "Copy constructor called" << std::endl;
    this->type = other.type;
    return ;
}}


WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {{
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal deconstructor called" << std::endl;
    return ;
}

//-----------------------------------------------------
//               FUNCTIONS
//----------------------------------------------------

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal make sounds!" << std::endl;
}

std::string WrongAnimal::getType() const {
    return (this->type);
}