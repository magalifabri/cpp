#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string SuperTrapName) : FragTrap(SuperTrapName), NinjaTrap(SuperTrapName)
{
	std::cout << "SuperTrap constructor called(" << SuperTrapName << ")\n"
	<< "Booting sequence complete.\n"
	<< CYAN " > '<message>'\n" RESET;
	FragTrap::lv = 1;
	FragTrap::name = SuperTrapName;
	// NinjaTrap::meleeAtkDmg = 60;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "SuperTrap destructor called (" << FragTrap::name << ")\n"
	<< CYAN " > '<message>'\n" RESET;
}
