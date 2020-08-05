#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include <iostream>
#include <string>
#include "Zombie.hpp"

class ZombieEvent
{
public:
	std::string type;
	void setZombieType(std::string);
	Zombie *newZombie(std::string);
};

#endif