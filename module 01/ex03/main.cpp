#include "main.hpp"

std::string get_growl(void)
{
	std::string growl[4];
	
	growl[0] = "bwwrrraaaahhh";
	growl[1] = "grrruuaaahh";
	growl[2] = "raaawwwhhh";
	growl[3] = "bhuuuaaaahhh";
	return (growl[rand() % 3]);
}

std::string createRandomName(void)
{
	std::string vowels;
	std::string consonants;
	char name[4];

	vowels = "aeuioy";
	consonants = "qwrtpsdfghjklzxcvbnm";
	name[0] = consonants[rand() % 20];
	name[1] = vowels[rand() % 6];
	name[2] = consonants[rand() % 20];
	name[3] = '\0';
	return (name);
}

/*
** Function Summary:
** 	- create a zombie with a random name
** 	- have the zombie announce itself
*/
Zombie randomChump(void)
{
	Zombie newZombie;
	
	newZombie.name = createRandomName();
	newZombie.type = "horseman";
	std::cout << "< " << newZombie.type << " (" << newZombie.name << ") > : 'Horseman " << newZombie.name << " reporting for duty!'\n";
	sleep(1);
	return (newZombie);
}

/*
** Function Summary:
** 	- create The Four Horsemen (4 stack zombies with randomChump names)
** 	- CREATE zombie horde
**	- zombie horde announces themselves
** 	- DELETE zombie horde array
*/
int main()
{
	ZombieHorde horde_1(3);
	Zombie horsemen[4];
	int i;

	srand(time(NULL));
	i = -1;
	while (++i < 4)
		horsemen[i] = randomChump();
	std::cout << BOLD "\n1st Horseman of the Apocalypse, " << horsemen[0].name
	<< RESET ": 'Alright, new recruits, announce yourselves!'\n\n" RESET;
	horde_1.announce();
	std::cout << "\nBut, oh, no!\nOne of the recruits is a 'suicide' boomer \
that infiltrated from an opposing zombie faction.\nHe explodes and the whole \
horde is blown to pieces.\nThe end.\n\n";
	delete[] horde_1.horde;
	return (0);
}
