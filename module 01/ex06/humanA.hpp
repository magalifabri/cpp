#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "weapon.hpp"
#include <string>
#include <iostream>

class HumanA
{
public:
	std::string name;
	Weapon &WeaponHumanA;
	HumanA(std::string name, Weapon &wpn) : name(name), WeaponHumanA(wpn) {}
	void attack();
};

#endif