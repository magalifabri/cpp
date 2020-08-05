#include "ZombieEvent.hpp"
#include "Zombie.hpp"

// set what type of zombie will populate this event
void ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}

// "create a zombie with the chosen type, name it, and return it"
Zombie *ZombieEvent::newZombie(std::string name)
{
	Zombie *newZombie;
	newZombie = new Zombie;
	newZombie->name = name;
	newZombie->type = this->type;
	newZombie->announce();
	return (newZombie);
}
