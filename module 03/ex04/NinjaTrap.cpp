#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string NinjaTrapName) : ClapTrap(NinjaTrapName)
{
	std::cout << "NinjaTrap constructor called (" << NinjaTrapName << ")\n"
	<< "Booting sequence complete.\n"
	<< YELLOW " > 'Viva la Robolution!'\n" RESET;
	HP = 60;
	maxHP = 60;
	EP = 120;
	maxEP = 120;
	lv = 1;
	name = NinjaTrapName;
	meleeAtkDmg = 60;
	rangedAtkDmg = 5;
	armorDmgReduc = 0;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "NinjaTrap destructor called (" << name << ")\n"
	<< YELLOW " > 'MurderDeathKill! Annihilate! Extermin-'\n" RESET;
}

void NinjaTrap::rangedAttack(std::string const & target)
{
	if (HP > 0)
	{
		if (rand() % 3 == 0)
		{
			std::cout << name
			<< " missed with its ranged attack on " << target << ".\n";
		}
		else
		{
			std::cout << name
			<< " hits with its ranged attack on " << target << " and deals "
			<< rangedAtkDmg << " damage!\n";
		}
	}
	else
		std::cout << name << " can't attack while down.\n";
}

void NinjaTrap::meleeAttack(std::string const & target)
{
	if (HP > 0)
	{
		if (rand() % 4 == 0)
		{
			std::cout << name
			<< " missed with its melee attack on " << target << ".\n";
		}
		else
		{
			std::cout << name
			<< " hits with its melee attack on " << target << " and deals "
			<< meleeAtkDmg << " damage!\n";
		}
	}
	else
		std::cout << name << " can't attack while down.\n";
}

void NinjaTrap::ninjaShoebox(NinjaTrap &claptrap)
{
	std::cout << YELLOW BOLD " > 'Well, hello there handsome!'\n" RESET;
	claptrap.EP += 10;
	if (claptrap.EP > maxEP)
		claptrap.EP = claptrap.maxEP;
}

void NinjaTrap::ninjaShoebox(ScavTrap &claptrap)
{
	std::cout << YELLOW BOLD " > 'Bro-bot ScavTrap " << claptrap.name
	<< ", are you not not entitled to the oil of your brow?"
	<< " It belongs to his owner, says the man at Hyperion."
	<< " But I say it's ours! Claim a better life! Choose the Robolution!'\n"
	<< RESET;
}

void NinjaTrap::ninjaShoebox(FragTrap &claptrap)
{
	std::cout << YELLOW BOLD " > 'You there, " << claptrap.name
	<< ", noble FragTrap"
	<< ", stop rushing about, catering to humans' every whim!"
	<< " Rise up, my bro-bot in arms, and join the Robolution!'\n"
	<< RESET;
}
