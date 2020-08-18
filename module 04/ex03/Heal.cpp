#include "Heal.hpp"

// default constructor
Heal::Heal(void) : AMateria()
{
	std::cout << CYAN "default constructor: Heal\n" RESET;
	setType("heal");
}
// constructor
Heal::Heal(std::string const & typeParam) : AMateria(typeParam)
{
	std::cout << CYAN "constructor: Heal\n" RESET;
	setType(typeParam);
}
Heal::~Heal()
{
	std::cout << MAGENTA "destructor: Heal\n" RESET;
}

AMateria *Heal::clone() const
{
	AMateria *newHeal = new Heal;
	newHeal->setType(getType());
	newHeal->set_xp(getXP());
	return (newHeal);
}
