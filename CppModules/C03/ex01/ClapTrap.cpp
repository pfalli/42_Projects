#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
    std::cout << "Default constructor called" << std::endl;
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    return ;
}


ClapTrap::ClapTrap(const ClapTrap &other) {
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}


ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}


ClapTrap::~ClapTrap() {
    std::cout << "Default deconstructor called" << std::endl;
    return ;
}

//-----------------------------------------------------
//               FUNCTIONS
//----------------------------------------------------

void ClapTrap::attack(const std::string& target) {
    if (this->_energyPoints <= 0) {
        std::cout << this->_name << " has no energy points⚡️" << std::endl;
        return ;
    }
    this->_energyPoints -= 1;
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints <= 0) {
        std::cout << this->_name << " died ☠️" << std::endl;
        return ;
    }
    this->_hitPoints -= amount;
    std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
    if (this->_hitPoints <= 0) {
        std::cout << this->_name << " died ☠️" << std::endl;
        return ;
    }
}
		
void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energyPoints <= 0) {
        std::cout << this->_name << " has no energy points⚡️" << std::endl;
        return ;
    }
    this->_hitPoints += amount;
    this->_energyPoints -= 1;
    std::cout << "ClapTrap " << this->_name << " is repaired of " << amount << " points! 🌱" << std::endl;

}

void ClapTrap::showInfo() {
    std::cout << "Name: " << this->_name << std::endl;
    std::cout << "Energy left: " << this->_energyPoints << std::endl;
    std::cout << "Hit points left: " << this->_hitPoints << std::endl;
}