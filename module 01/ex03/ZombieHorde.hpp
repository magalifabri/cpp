#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

// #include <iostream>
// #include <string>
#include "Zombie.hpp"
#include "main.hpp"

// class ZombieEvent
// {
// public:
// 	std::string type;
// 	void setZombieType(std::string);
// 	Zombie *newZombie(std::string);
// };

class ZombieHorde
{
public:
	ZombieHorde(int);
	~ZombieHorde();
	Zombie *horde;
	int numberOfZombies;
	void announce();
};

#endif