#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Weapon {
public:
    Weapon(std::string name);
    ~Weapon();
	std::string const &getType() const;
	void setType(std::string type);

private:
    std::string _type;

};

#endif // WEAPON_HPP
