#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
public:
    HumanB(std::string name);
    ~HumanB();
	void attack();
	void setWeapon(Weapon &weapon);

private:
    Weapon* _weapon; // pointer
    std::string _name;

};

#endif // HUMANB_HPP
