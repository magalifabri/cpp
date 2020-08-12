#include "Peon.hpp"

Peon::Peon(std::string peonName) : Victim(peonName)
{
	name = peonName;
	std::cout << "Zog zog\n";
}

Peon::~Peon(void)
{
	std::cout << "Bleuark...\n";
}

void Peon::getPolymorphed(void) const
{
	std::cout << name << " has been turned into a pink pony!\n";
}
