#ifndef APPRENTICE_HPP
#define APPRENTICE_HPP

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include <iostream>
#include <string>

class Apprentice: public Sorcerer
{
	public:
	Apprentice(std::string name, std::string title);
	~Apprentice();
	void polymorph(Victim const &victim) const;
	void polymorph(Peon const &peon) const;
};

#endif