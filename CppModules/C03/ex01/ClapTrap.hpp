#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

#include <iostream>
#include <string>

class ClapTrap {
	protected:
	    std::string _name;
		int _hitPoints; // Life
		int _energyPoints; // energy to attack
		int _attackDamage;

	public:
	    ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
        ClapTrap &operator=(const ClapTrap &other);
	    ~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void showInfo();
	
};

#endif 
