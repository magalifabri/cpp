#include "Victim.hpp"

Victim::Victim(std::string victimName)
{
	name = victimName;
	std::cout << "Some random victim called " << name << " just appeared!\n";
}

Victim::~Victim(void)
{
	std::cout << "Victim " << name << " just died for no apparent reason!\n";
}

void Victim::getPolymorphed(void) const
{
	std::cout << name << " has been turned into a cute little sheep!\n";
}
