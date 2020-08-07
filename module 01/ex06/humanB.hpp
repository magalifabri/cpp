#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "weapon.hpp"
#include <string>
#include <iostream>

class HumanB
{
public:
	HumanB();
	HumanB(std::string);
	Weapon *WeaponHumanB;
	std::string name;
	void setWeapon(Weapon &);
	void attack();
};

#endif