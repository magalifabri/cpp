#include "Ice.hpp"

// default constructor
Ice::Ice(void) : AMateria()
{
	std::cout << CYAN "default constructor: Ice\n" RESET;
	setType("ice");
}
// constructor
Ice::Ice(std::string const & typeParam) : AMateria(typeParam)
{
	std::cout << CYAN "constructor: Ice\n" RESET;
	setType(typeParam);
}
Ice::~Ice()
{
	std::cout << MAGENTA "destructor: Ice\n" RESET;
}

AMateria *Ice::clone() const
{
	AMateria *newIce = new Ice;
	newIce->setType(getType());
	newIce->set_xp(getXP());
	return (newIce);
}
