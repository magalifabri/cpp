#ifndef PEON_HPP
#define PEON_HPP

#include "Victim.hpp"
#include <iostream>
#include <string>

class Peon: public Victim
{
	public:
	Peon(std::string name);
	~Peon();
	void getPolymorphed() const;
};

#endif