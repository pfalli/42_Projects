#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
    this->_name = name;
    this->_weapon = NULL; // pointer
}

HumanB::~HumanB() {
    // Destructor implementation
}

void HumanB::attack(){
    if (this->_weapon != NULL && this->_weapon->getType() != "") {
        std::cout << _name << " attacks with their " << this->_weapon->getType() << std::endl;
    } else {
        std::cout << _name << " doesn't have a weapon to attack." << std::endl;
    }
}


void HumanB::setWeapon(Weapon &weapon){
	this->_weapon = &weapon;
}