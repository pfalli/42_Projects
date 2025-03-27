#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    std::cout << " FragTrap: Default constructor called" << std::endl;
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    return ;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap: Default deconstructor called" << std::endl;
    return ;
}

//-----------------------------------------------------
//               FUNCTIONS
//----------------------------------------------------

void FragTrap::highFivesGuys(void) {
    std::cout << this->_name << " asks high five 🙏" << std::endl;
}
