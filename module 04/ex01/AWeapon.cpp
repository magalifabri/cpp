#include "AWeapon.hpp"

/* default constructor (coplien 1/4) */
AWeapon::AWeapon(void)
{
	std::cout << CYAN "Default constructor called: AWeapon\n" RESET;
}

/* constructor */
AWeapon::AWeapon(std::string const &nameParam, int APCostParam, int dmgParam)
{
	std::cout << CYAN "Constructor called: AWeapon\n" RESET;
	name = nameParam;
	APCost = APCostParam;
	dmg = dmgParam;
}

/* copy constructor (coplien 2/4) */
AWeapon::AWeapon(const AWeapon &weapon)
{
	std::cout << CYAN "Copy constructor called\n" RESET;
	operator=(weapon);
}

/* assignment operator overload (coplien 3/4) */
void AWeapon::operator=(const AWeapon &weapon)
{
	std::cout << CYAN "Assignation operator called\n" RESET;
	name = weapon.name;
	APCost = weapon.APCost;
	dmg = weapon.dmg;
}

/* destructor (coplien 4/4) */
AWeapon::~AWeapon()
{
	std::cout << CYAN "Destructor called: AWeapon\n" RESET;
}

std::string AWeapon::getName() const
{
	return (name);
}

int AWeapon::getAPCost() const
{
	return (APCost);
}

int AWeapon::getDmg() const
{
	return (dmg);
}
