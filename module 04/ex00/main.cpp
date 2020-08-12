#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Apprentice.hpp"
#include <iostream>
#include <string>


/* -------------------------- UTIL FUNCTIONS ------------------------------- */


std::ostream &operator<<(std::ostream &os, const Sorcerer &sorcerer)
{
	os << "I am " << sorcerer.name << ", " << sorcerer.title << ", and I like ponies!\n";
	return (os);
}

std::ostream &operator<<(std::ostream &os, const Victim &victim)
{
	os << "I'm " << victim.name << " and I like otters!\n";
	return (os);
}


/* -------------------------- MAIN ----------------------------------------- */


int main()
{
	srand(time(NULL));
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	std::cout << robert << jim << joe;
	robert.polymorph(jim);
	robert.polymorph(joe);
	Apprentice harry("Harry", "junior wizard");
	harry.polymorph(jim);
	harry.polymorph(joe);
}