#include "main.hpp"

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
** 	loop:
** 		create a random name
** 		start the clock
** 		write the name to the screen
** 		check if the user input matches the name and was given in time
** 		if so, create a zombie by that name 
*/
void create_zombie_soldiers(Zombie *horde[], ZombieEvent apocalypse,
int &zombie_i)
{
	int counter;
	std::string askedName;
	std::string answeredName;
    long long start;

	sleep(3);
	counter = -1;
	while (++counter < 10)
	{
		askedName = createRandomName();
		start = get_current_time();
		std::cout << YELLOW BOLD << askedName <<  "?\n" RESET;
		std::getline(std::cin, answeredName);
		if (get_current_time() - start > 2000 
		|| answeredName.compare(askedName) != 0)
			std::cout << RED BOLD "[absence noted]\n\n" RESET;
		else
			horde[zombie_i++] = apocalypse.newZombie(askedName);
		if (counter - zombie_i >= 2)
		{
			std::cout << RED BOLD "Darn it! Cancelled again!\n" RESET;
			break ;
		}
	}
}

/*
** Function Summary:
** 	- create a zombie event
** 	- set what type of zombie will populate this event
** 	- create The Four Horsemen (4 stack zombies with randomChump names)
** 	- CREATE zombies for the apocalyse / "check attendance"
** 	- CHECK if enough zombs are present for the Apocalypse to proceed
** 	- DELETE Apoca Zombs
*/
int main()
{
	ZombieEvent apocalypse;
	Zombie horsemen[4];
	Zombie *horde[10];
	int zombie_i;
	apocalypse.setZombieType("Apoca Zomb");
	int i = -1;
	while (++i < 4)
		horsemen[i] = randomChump();
	std::cout << BOLD "\n1st Horseman of the Apocalypse, " << horsemen[0].name << RESET ": 'Alright, let's check the attendance to see if we can proceed with the Apocalypse.\n" BOLD "When I call out your name, repeat it. " UNDERLINE "QUICKLY!'\n\n" RESET;
	create_zombie_soldiers(horde, apocalypse, zombie_i);
	horde[zombie_i] = NULL;
	if (zombie_i > 7)
		std::cout << GREEN BOLD "Apocalyse is a go! Give 'em HELL!\n" RESET;
	while (--zombie_i > -1)
		delete horde[zombie_i];
	return (0);
}
