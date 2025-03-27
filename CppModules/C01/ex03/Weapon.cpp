#include "Weapon.hpp"

Weapon::Weapon(std::string name) {
    this->_type = name;
}

Weapon::~Weapon() {
    
}

const std::string& Weapon::getType() const{
    return _type;   // Return a reference to the type member variable
}

void Weapon::setType(std::string type) {
    this->_type = type;
}