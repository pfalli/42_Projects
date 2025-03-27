#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
	    ScavTrap(std::string name);
	    ~ScavTrap();

		void guardGate();
		void attack(const std::string& target);
	
};

#endif //
