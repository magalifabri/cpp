#include "PowerFist.hpp"

/* default constructor */
PowerFist::PowerFist(void) : AWeapon()
{
	std::cout << CYAN "Default constructor called: PowerFist\n" RESET;
}

/* constructor */
PowerFist::PowerFist(std::string wpnName, int wpnAPCost, int wpnDmg)
: AWeapon(wpnName, wpnAPCost, wpnDmg)
{
	std::cout << CYAN "Constructor called: PowerFist\n" RESET;
	name = wpnName;
	APCost = wpnAPCost;
	dmg = wpnDmg;
}

/* destructor */
PowerFist::~PowerFist(void)
{
	std::cout << CYAN "Destructor called: PowerFist\n" RESET;
}

void PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *\n";
}
