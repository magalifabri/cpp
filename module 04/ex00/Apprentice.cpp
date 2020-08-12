#include "Apprentice.hpp"

Apprentice::Apprentice(std::string apprenticeName, std::string apprenticeTitle)
: Sorcerer(apprenticeName, apprenticeTitle)
{
	name = apprenticeName;
	title = apprenticeTitle;
	std::cout << name << "'I'm ready to learn!'\n";
}

Apprentice::~Apprentice(void)
{
	std::cout << name << ", " << title << ", blew himself to bits.\n";
}

void Apprentice::polymorph(Victim const &victim) const
{
	int diceRoll;

	diceRoll = rand() % 20;
	if (diceRoll >= 10)
		victim.getPolymorphed();
	else
	{
		std::cout << name << " attempts to polymorph " << victim.name
		<< ", but there's an explosion and " << name
		<< " looks a bit crispy around the edges.\n";
	}
}

void Apprentice::polymorph(Peon const &peon) const
{
	int diceRoll;

	diceRoll = rand() % 20;
	if (diceRoll >= 10)
		peon.getPolymorphed();
	else
	{
		std::cout << name << " attempts to polymorph " << peon.name
		<< ", but there's an explosion and " << name
		<< " looks a bit crispy around the edges.\n";
	}
}
