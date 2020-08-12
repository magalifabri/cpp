#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string sorcName, std::string sorcTitle)
{
	name = sorcName;
	title = sorcTitle;
	std::cout << name << ", " << title << ", is born!\n";
}

Sorcerer::~Sorcerer(void)
{
	std::cout << name << ", " << title
	<< ", is dead. Consequences will never be the same!\n";
}

Sorcerer::Sorcerer(const Sorcerer &x)
{
	std::cout << "Copy constructor called\n";
	operator=(x);
}

void Sorcerer::operator=(const Sorcerer &x)
{
	std::cout << "Assignation operator called\n";
	name = x.name;
	title = x.title;
}

void Sorcerer::polymorph(Victim const &victim) const
{
	victim.getPolymorphed();
}

void Sorcerer::polymorph(Peon const &peon) const
{
	peon.getPolymorphed();
}
