#include "humanB.hpp"

HumanB::HumanB(std::string humanName)
{
	name = humanName;
}

void HumanB::setWeapon(Weapon &weaponName)
{
	WeaponHumanB = &weaponName;
}

void HumanB::attack(void)
{
	std::cout << name << " attacks with his " << WeaponHumanB->getType() << "\n";
}
