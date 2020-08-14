#include "PlasmaRifle.hpp"

/* default constructor */
PlasmaRifle::PlasmaRifle(void) : AWeapon()
{
	std::cout << CYAN "Default constructor called: PlasmaRifle\n" RESET;
}

/* constructor */
PlasmaRifle::PlasmaRifle(std::string const &nameParam, int APCostParam
, int dmgParam) : AWeapon(nameParam, APCostParam, dmgParam)
{
	std::cout << CYAN "Constructor called: PlasmaRifle\n" RESET;
	name = nameParam;
	APCost = APCostParam;
	dmg = dmgParam;
}

/* destructor */
PlasmaRifle::~PlasmaRifle(void)
{
	std::cout << CYAN "Destructor called: PlasmaRifle\n" RESET;
}

void PlasmaRifle::attack(void) const
{
	std::cout << "* piouuu piouuu piouuu *\n";
}
