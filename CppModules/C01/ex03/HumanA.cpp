#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _weapon(weapon), _name(name)  {
}

HumanA::~HumanA() {
    // Destructor implementation
}

void HumanA::attack(){
	if (this->_weapon.getType() != "") {
        std::cout << _name << " attacks with their " << this->_weapon.getType() << std::endl;
    } else {
        std::cout << _name << " doesn't have a weapon to attack." << std::endl;
    }
}

