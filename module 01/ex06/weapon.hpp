#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
public:
	Weapon();
	Weapon(std::string);
	std::string type;
	std::string getType() const;
	void setType(std::string);
};

#endif