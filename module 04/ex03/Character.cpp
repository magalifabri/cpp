#include "Character.hpp"

// default constructor (coplien 1/4)
Character::Character(void)
{
	std::cout << CYAN "default constructor: Character\n" RESET;
	inventory[0] = nullptr;
	inventory[1] = nullptr;
	inventory[2] = nullptr;
	inventory[3] = nullptr;
}
// constructor
Character::Character(std::string const &nameParam)
{
	std::cout << CYAN "constructor: Character: " << nameParam << "\n" RESET;
	name = nameParam;
	inventory[0] = nullptr;
	inventory[1] = nullptr;
	inventory[2] = nullptr;
	inventory[3] = nullptr;
}
// copy constructor (coplien 2/4)
Character::Character(const Character &character)
{
	std::cout << CYAN "copy constructor: Character: " << character.getName() << "\n" RESET;
	inventory[0] = nullptr;
	inventory[1] = nullptr;
	inventory[2] = nullptr;
	inventory[3] = nullptr;
	operator=(character);
}
// assignment operator (coplien 3/4)
void Character::operator=(const Character &character)
{
	std::cout << CYAN "assignment operator: Character: " << character.getName() << "\n" RESET;
	
	int i;

	i = -1;
	while (++i < 4)
	{
		if (inventory[i] != nullptr)
		{
			delete inventory[i];
			inventory[i] = nullptr;
		}
	}
	i = -1;
	while (++i < 4)
		if (character.inventory[i] != nullptr)
			inventory[i] = character.inventory[i]->clone();
	name = character.getName();
}
// destructor (coplien 4/4)
Character::~Character()
{
	int i;

	std::cout << MAGENTA "destructor: Character: " << name << "\n" RESET;
	i = -1;
	while (++i < 4)
	{
		if (inventory[i] != nullptr)
		{
			delete inventory[i];
			inventory[i] = nullptr;
		}
	}
}

std::string const & Character::getName() const
{
	return (name);
}
void Character::equip(AMateria* m)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (inventory[i] == m)
		{
			std::cout << RED "This exact Materia has already been equipped\n" RESET;
			return ;
		}
	}
	i = -1;
	while (++i < 4)
	{
		if (inventory[i] == nullptr)
		{
			inventory[i] = m;
			std::cout << name << " equipped " << m->getType() << " in inventory slot " << i << "\n";
			return ;
		}
	}
	std::cout << RED "cannot equip Materia " << m->getType() <<": inventory full\n" RESET;
}
void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		std::cout << RED "cannot unequip Materia: " << idx << " is an incorrect index\n" RESET;
	else if (inventory[idx] == nullptr)
		std::cout << RED "cannot unequip Materia: no Materia equipped in inventory slot" << idx << "\n" RESET;
	else
	{
		std::cout << name << " unequipped the Materia " << inventory[idx]->getType() << " from inventory slot " << idx << std::endl;
		inventory[idx] = nullptr;
	}
}
void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
		std::cout << RED "cannot use materia: incorrect index\n" RESET;
	else if (inventory[idx] == nullptr)
		std::cout << RED "cannot use materia: no materia equipped in that inventory slot\n" RESET;
	else
		inventory[idx]->use(target);
}
void Character::printInventory(void)
{
	int i;
	std::cout << name << "'s inventory content:\n";
	i = -1;
	while (++i < 4)
	{
		if (inventory[i] != nullptr)
			std::cout << " - equipped in inventory slot " << i << " " << inventory[i]->getType() << "\n";
	}
}
