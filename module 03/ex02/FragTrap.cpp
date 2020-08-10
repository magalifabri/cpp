#include "FragTrap.hpp"

FragTrap::FragTrap(std::string FragTrapName) : ClapTrap(FragTrapName)
{
	std::cout << "FragTrap constructor called (" << FragTrapName << ")\n"
	<< "Booting sequence complete.\n"
	<< CYAN BOLD " > 'Hey, best friend!'\n" RESET;
	HP = 100;
	maxHP = 100;
	EP = 100;
	maxEP = 100;
	lv = 1;
	name = FragTrapName;
	meleeAtkDmg = 30;
	rangedAtkDmg = 20;
	armorDmgReduc = 5;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called (" << name << ")\n"
	<< CYAN BOLD " > 'Argh arghargh death gurglegurgle urgh.. death.'\n" RESET;
}

void FragTrap::rangedAttack(std::string const & target)
{
	if (HP > 0)
	{
		if (rand() % 3 == 0)
		{
			std::cout << "FR4G-TP " << name
			<< " missed with its ranged attack on " << target << ".\n";
		}
		else
		{
			std::cout << "FR4G-TP " << name
			<< " hits with its ranged attack on " << target << " and deals "
			<< rangedAtkDmg << " damage!\n";
		}
	}
	else
		std::cout << "FR4G-TP " << name << " can't attack while down.\n";
}

void FragTrap::meleeAttack(std::string const & target)
{
	if (HP > 0)
	{
		if (rand() % 4 == 0)
		{
			std::cout << "FR4G-TP " << name
			<< " missed with its melee attack on " << target << ".\n";
		}
		else
		{
			std::cout << "FR4G-TP " << name
			<< " hits with its melee attack on " << target << " and deals "
			<< meleeAtkDmg << " damage!\n";
		}
	}
	else
		std::cout << "FR4G-TP " << name << " can't attack while down.\n";
}

void FragTrap::takeDmg(unsigned int amount)
{
	if (HP == 0)
		std::cout << "FR4G-TP " << name << " is already down.\n";
	else
	{
		std::cout << "FR4G-TP " << name << " takes "
		<< amount - armorDmgReduc << " damage";
		HP -= (amount - armorDmgReduc);
		if (HP < 0)
			HP = 0;
		if (HP == 0)
			std::cout << ", falls to 0 HP and shuts down.\n"
			<< MAGENTA BOLD " > 'Robot down!'\n" RESET;
		else
			std::cout << " and falls to " << HP << " HP.\n";
	}
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (HP == maxHP)
		std::cout << "FR4G-TP " << name << " is not in need of repair.\n";
	else
	{
		std::cout << "FR4G-TP " << name << " repairs " << amount << " damage.";
		if (HP == 0)
			std::cout << " It's no longer critically damaged and reboots.";
		HP += amount;
		if (HP > maxHP)
			HP = maxHP;
		std::cout << " It is now at " << HP << " HP.\n";
		if ((HP - amount) <= 0)
			std::cout << MAGENTA BOLD " > 'Ha ha ha! I LIVE! Hahaha!'\n" RESET;
	}
}

void FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	int attackNumber;

	if (HP < 0)
		std::cout << "FR4G-TP " << name << " can't attack while down.\n";
	else if (EP < 25)
	{
		std::cout << "FR4G-TP " << name
		<< " doesn't have enough EP to use VaultHunter.exe.\n";
	}
	else
	{
		attackNumber = rand() % 5;
		if (attackNumber == 0)
			std::cout << "FR4G-TP " << name << " activates Funzerker and goes \
wild with two ammo-regenerating, auto-firing machine guns, focussing on "
<< target << ".\n" << MAGENTA BOLD" > 'I'm a sexy dinosaur! Rawr!'\n" RESET;
		else if (attackNumber == 1)
			std::cout << "FR4G-TP " << name << " activates Gun Wizard and \
unloads on " << target << " with increased fire rate.\n"
<< MAGENTA BOLD" > 'You can call me Gundalf!'\n" RESET;
		else if (attackNumber == 2)
			std::cout << "FR4G-TP " << name << " activates One Shot Wonder and\
with every pull of the trigger, unloads a whole magazine of ammo at " << target
<< ".\n"
<< MAGENTA BOLD " > 'Kill, reload! Kill, reload! KILL! RELOAD!'\n" RESET;
		else if (attackNumber == 3)
			std::cout << "FR4G-TP " << name << " activates Laser Inferno, \
causing a disco ball to appear above Claptrap's Head, constantly shooting \
lasers at " << target << ".\n" << MAGENTA BOLD " > 'Boogie time!'\n" RESET;
		else if (attackNumber == 4)
			std::cout << "FR4G-TP " << name << " activates Pirate Ship Mode, \
turns into a mini-pirate ship with cannons and fires them at " << target << ".\
\n" << MAGENTA BOLD " > 'I feel a joke about poop decks coming on!'\n" RESET;
		EP -= 25;
	}
}
