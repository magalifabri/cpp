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

void ScavTrap::meleeAttack(std::string const & target)
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

void ScavTrap::takeDmg(unsigned int amount)
{
	if (HP == 0)
		std::cout << "SC4V-TP " << name << " is already down.\n";
	else
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
}

// void ScavTrap::beRepaired(unsigned int amount)
// {
// 	if (HP == maxHP)
// 		std::cout << "SC4V-TP " << name << " is not in need of repair.\n";
// 	else
// 	{
// 		std::cout << "SC4V-TP " << name << " repairs " << amount << " damage.";
// 		if (HP == 0)
// 			std::cout << " It is no longer critically damaged and boots back up.";
// 		HP += amount;
// 		if (HP > maxHP)
// 			HP = maxHP;
// 		std::cout << " It is now at " << HP << " HP.\n";
// 		if ((HP - amount) <= 0)
// 			std::cout << MAGENTA BOLD " > 'Ha ha ha! I LIVE! Hahaha!'\n" RESET;
// 	}
// }

// void FragTrap::vaulthunter_dot_exe(std::string const & target)
// {
// 	int attackNumber;

// 	if (EP < 25)
// 		std::cout << "SC4V-TP " << name << " doesn't have enough EP to use VaultHunter.exe.\n";
// 	else
// 	{
// 		attackNumber = rand() % 4;
// 		if (attackNumber == 0)
// 			std::cout << "SC4V-TP " << name << " activates Funzeker and goes wild with two ammo-regenerating, auto-firing machine guns, focussing on " << target << ".\n" << MAGENTA BOLD" > 'I'm a sexy dinosaur! Rawr!'\n" RESET;
// 		else if (attackNumber == 1)
// 			std::cout << "SC4V-TP " << name << " activates Gun Wizard and unloads on " << target << " with increased fire rate.\n" << MAGENTA BOLD" > 'You can call me Gundalf!'\n" RESET;
// 		else if (attackNumber == 2)
// 			std::cout << "SC4V-TP " << name << " activates One Shot Wonder and with one pull of the trigger, unloads all remaining ammo at " << target << ".\n" << MAGENTA BOLD " > 'Kill, reload! Kill, reload! KILL! RELOAD!'\n" RESET;
// 		else if (attackNumber == 3)
// 			std::cout << "SC4V-TP " << name << " activates Laser Inferno, causing a disco ball to appear above Claptrap's Head, constantly shooting lasers at " << target << ".\n" << MAGENTA BOLD " > 'Boogie time!'\n" RESET;
// 		else if (attackNumber == 4)
// 			std::cout << "SC4V-TP " << name << " activates Pirate Ship Mode, turns into a mini-pirate ship with cannons and fires them at " << target << ".\n" << MAGENTA BOLD " > 'I feel a joke about poop decks coming on!'\n" RESET;
// 		EP -= 25;
// 	}
// }
