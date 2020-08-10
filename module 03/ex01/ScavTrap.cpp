#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string ScavTrapName)
{
	std::cout << "Constructor called (" << name << ")\n"
	<< "Booting sequence complete.\n"
	<< CYAN BOLD " > 'I wil be right here! Guarding this gate!'\n" RESET;
	HP = 100;
	maxHP = 100;
	EP = 50;
	maxEP = 50;
	lv = 1;
	name = ScavTrapName;
	meleeAtkDmg = 20;
	rangedAtkDmg = 15;
	armorDmgReduc = 3;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor called (" << name << ")\n"
	<< CYAN BOLD " > 'No... Who will... guard the gate...?'\n" RESET;
}

void ScavTrap::rangedAttack(std::string const & target)
{
	if (HP > 0)
	{
		if (rand() % 3 == 0)
		{
			std::cout << "SC4V-TP " << name
			<< " missed with its ranged attack on " << target << ".\n";
		}
		else
		{
			std::cout << "SC4V-TP " << name
			<< " hits with its ranged attack on " << target << " and deals "
			<< rangedAtkDmg << " damage!\n"
			<< MAGENTA BOLD " > 'For the RedBelly!'\n" RESET;
		}
	}
	else
		std::cout << "SC4V-TP " << name << " can't attack while down.\n";
}

void ScavTrap::meleeAttack(std::string const & target)
{
	if (HP > 0)
	{
		if (rand() % 4 == 0)
		{
			std::cout << "SC4V-TP " << name
			<< " missed with its melee attack on " << target << ".\n";
		}
		else
		{
			std::cout << "SC4V-TP " << name << " hits with its melee attack on "
			<< target << " and deals " << meleeAtkDmg << " damage!\n"
			<< MAGENTA BOLD " > 'For the RedBelly!'\n" RESET;
		}
	}
	else
		std::cout << "SC4V-TP " << name << " can't attack while down.\n";
}

void ScavTrap::takeDmg(unsigned int amount)
{
	if (HP > 0)
	{
		std::cout << "SC4V-TP " << name
		<< " takes " << amount - armorDmgReduc << " damage";
		HP -= (amount - armorDmgReduc);
		if (HP < 0)
			HP = 0;
		if (HP == 0)
			std::cout << ", falls to 0 HP and shuts down.\n"
			<< MAGENTA BOLD " > 'Guard the gate! I need a break...'\n" RESET;
		else
			std::cout << " and falls to " << HP << " HP.\n";
	}
	else
		std::cout << "SC4V-TP " << name << " is already down.\n";
}

void ScavTrap::challengeNewcomer(void)
{
	int challengeNumber;

	challengeNumber = rand() % 5;
	if (challengeNumber == 0)
		std::cout << MAGENTA BOLD "Guarding gates is FUN!\n" RESET;
	else if (challengeNumber == 1)
		std::cout << MAGENTA BOLD "Halt, moon citizen!\n" RESET;
	else if (challengeNumber == 2)
	{
		std::cout << MAGENTA BOLD
		<< "I'm not to let ANYONE in through here!\n" RESET;
	}
	else if (challengeNumber == 3)
	{
		std::cout << MAGENTA BOLD
		<< "Here as fresh meat for the recruitment grinder?\n" RESET;
	}
	else
		std::cout << MAGENTA BOLD "Guarding gates is the new hotness!\n" RESET;
}
