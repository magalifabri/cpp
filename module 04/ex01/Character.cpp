#include "Character.hpp"

/* default constructor (coplien 1/4) */
Character::Character()
{
	std:: cout << CYAN "Default constructor called: Character\n" RESET;
}

/* constructor */
Character::Character(std::string const &nameParam)
{
	std:: cout << CYAN "Constructor called: Character\n" RESET;
	name = nameParam;
	AP = 40;
	maxAP = 40;
	weapon = nullptr;
}

/* copy constructor (coplien 2/4) */
Character::Character(Character const &character)
{
	std:: cout << CYAN "Copy constructor called: Character\n" RESET;
	operator=(character);
}

/* assignment operator overload (coplien 3/4) */
void Character::operator=(Character const &character)
{
	std:: cout << CYAN "Assignment Operator called: Character\n" RESET;
	name = character.getName();
	AP = character.AP;
	maxAP = 40;
	weapon = character.weapon;
}

/* destructor (coplien 4/4) */
Character::~Character()
{
	std:: cout << CYAN "Destructor called: Character\n" RESET;
}

void Character::recoverAP()
{
	AP += 10;
	if (AP > maxAP)
		AP = maxAP;
	std::cout << name << " restored 10 AP. (" << AP << "/40 AP)\n";
}

void Character::equip(AWeapon* weaponParam)
{
	weapon = weaponParam;
	std::cout << name << " equipped " << weapon->getName() << ".\n";
}

void Character::attack(A_Enemy *enemy)
{
	if (weapon == nullptr)
	{
		std::cout << RED "Can't attack: no weapon equipped.\n" RESET;
		return ;
	}
	if (AP - weapon->getAPCost() < 0)
	{
		std::cout << RED "Can't attack: not enough AP. ("
		<< AP << "/40 AP)\n" RESET;
		return ;
	}
	std::cout << name << " attacks " << enemy->getType() << " with a "
	<< weapon->getName() << ".\n";
	weapon->attack();
	enemy->takeDamage(weapon->getDmg());
	AP -= weapon->getAPCost();
	if (enemy->getHP() <= 0)
		enemy->~A_Enemy();
}

std::string Character::getName() const
{
	return (name);
}

int Character::getAP() const
{
	return (AP);
}

std::string Character::getWeaponType() const
{
	if (weapon == nullptr)
		return ("");
	return (weapon->getName());
}
