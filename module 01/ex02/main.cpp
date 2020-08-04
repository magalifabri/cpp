#include <iostream>
#include <string>
// #include <stdlib.h>
#include <unistd.h>
#include <ctime>
#include <sys/time.h>

#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define REVERSED "\033[7m"


// ZOMBIE CLASS STUFF ---------------------------------------------------------


class Zombie
{
public:
	Zombie(void);
	~Zombie(void);
	std::string type;
	std::string name;
	void announce(void);
};

Zombie::Zombie(void)
{
	// std::cout << "constructor called\n";
}
Zombie::~Zombie(void)
{
	// std::cout << "destructor called\n";
}

std::string get_growl(void)
{
	std::string growl[4];
	
	growl[0] = "bwwrrraaaahhh";
	growl[1] = "grrruuaaahh";
	growl[2] = "raaawwwhhh";
	growl[3] = "bhuuuaaaahhh";
	return (growl[rand() % 3]);
}
void Zombie::announce(void)
{
	std::cout << "< " << this->type << " (" << this->name << ") > : '" << get_growl() << ".. " << this->name << "! Brains, please.'\n";
}


// ZOMBIE EVENT CLASS STUFF ---------------------------------------------------


class ZombieEvent
{
public:
	std::string type;
	void setZombieType(std::string);
	Zombie *newZombie(std::string);
};

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


// MAIN -----------------------------------------------------------------------


std::string createRandomName(void)
{
	std::string vowels;
	std::string consonants;
	char name[4];

	srand(time(NULL));
	vowels = "aeuioy";
	consonants = "qwrtpsdfghjklzxcvbnm";
	name[0] = consonants[rand() % 20];
	name[1] = vowels[rand() % 6];
	name[2] = consonants[rand() % 20];
	name[3] = '\0';
	return (name);
}

void report(Zombie zombie)
{
	std::cout << "< " << zombie.type << " (" << zombie.name << ") > : Horseman " << zombie.name << " reporting for duty!\n";
}

Zombie randomChump(void)
{
	// create a zombie with a random name
	Zombie newZombie;
	newZombie.name = createRandomName();
	newZombie.type = "horseman";
	// have the zombie announce itself
	report(newZombie);
	return (newZombie);
}

long long get_current_time(void)
{
	struct timeval tp;
	long long time;

	if (gettimeofday(&tp, 0) == -1)
		return (-1);
	time = tp.tv_sec;
	time *= 1000;
	time += (tp.tv_usec / 1000);
	return (time);
}

int main()
{
	// create a zombie event
	ZombieEvent apocalypse;
	// set what type of zombie will populate this event
	apocalypse.setZombieType("Apoca Zomb");

	// create The Four Horsemen (4 stack zombies with randomChump names)
	Zombie horseman_1;
	Zombie horseman_2;
	Zombie horseman_3;
	Zombie horseman_4;
	horseman_1 = randomChump();
	sleep(1);
	horseman_2 = randomChump();
	sleep(1);
	horseman_3 = randomChump();
	sleep(1);
	horseman_4 = randomChump();
	sleep(1);
	std::cout << "\n";

	// CREATE zombies for the apocalyse / "check attendance"
	Zombie *horde[10];
	int counter;
	int zombie_i;
	std::string askedName;
	std::string answeredName;
    long long start;

	std::cout << BOLD "1st Horseman of the Apocalypse, " << horseman_1.name << RESET ": 'Alright, let's check the attendance to see if we can go ahead with the Apocalypse.\n" BOLD "When I call out your name, repeat it. " UNDERLINE "QUICKLY!'\n\n" RESET;
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
			std::cout << RED BOLD "Apocalyse is cancelled\n" RESET;
			break ;
		}
	}
	horde[zombie_i] = NULL;
	if (zombie_i > 7)
		std::cout << GREEN BOLD "Apocalyse is a go\n" RESET;

	return (0);
}
