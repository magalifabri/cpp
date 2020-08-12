#ifndef SORCERER_HPP
#define SORCERER_HPP

#include "Victim.hpp"
#include "Peon.hpp"

#include <iostream>
#include <string>

class Sorcerer
{
	public:
	Sorcerer(std::string name, std::string title);
	Sorcerer(const Sorcerer &);
	void operator=(const Sorcerer &);
	~Sorcerer();
	std::string name;
	std::string title;
	void polymorph(Victim const &) const;
	void polymorph(Peon const &) const;
};

#endif