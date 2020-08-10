#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string ClapTrapName)
{
	std::cout << "ClapTrap constructor called (" << ClapTrapName << ")\n";
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called (" << name << ")\n";
}
