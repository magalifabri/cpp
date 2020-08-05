#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n)
{
	int i;

	// std::cout << "ZombieHorde constructor called\n";
	horde = new Zombie[n];
	i = -1;
	while (++i < n)
		horde[i].name = createRandomName();
	numberOfZombies = n;
}

ZombieHorde::~ZombieHorde(void)
{
	// std::cout << "ZombieHorde destructor called\n";
}

void ZombieHorde::announce(void)
{
	int i;

	i = -1;
	while (++i < numberOfZombies)
		horde[i].announce();
}