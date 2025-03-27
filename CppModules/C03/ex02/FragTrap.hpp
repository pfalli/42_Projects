#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	private:
	    // Add your private members here

	public:
	    FragTrap(std::string name);
	    ~FragTrap();

		void highFivesGuys(void);
	
};

#endif
