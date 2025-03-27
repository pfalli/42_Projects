#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    std::cout << " ScavTrap: Default constructor called" << std::endl;
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    return ;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap: Default deconstructor called" << std::endl;
    return ;
}

//-----------------------------------------------------
//               FUNCTIONS
//----------------------------------------------------

void ScavTrap::guardGate() {
    std::cout << GREEN "ScavTrap is now in Gate keeper mode." RESET << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (this->_energyPoints <= 0) {
        std::cout << this->_name << " has no energy points⚡️" << std::endl;
        return ;
    }
    this->_energyPoints -= 1;
    std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing damage!" << std::endl;
}
