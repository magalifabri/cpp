#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	public:
	// ClapTrap();
	ClapTrap(std::string ClapTrapName);
	~ClapTrap();
	int HP;
	int maxHP;
	int EP;
	int maxEP;
	int lv;
	std::string name;
	int meleeAtkDmg;
	int rangedAtkDmg;
	int armorDmgReduc;
	// void rangedAttack(std::string const & target);
	// void meleeAttack(std::string const & target);
	// void takeDmg(unsigned int amount);
};

#endif