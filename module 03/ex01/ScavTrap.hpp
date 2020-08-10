#ifndef SCRAVTRAP_HPP
#define SCRAVTRAP_HPP

#include <iostream>
#include <string>

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

class ScavTrap
{
	public:
	ScavTrap(std::string ScavTrapName);
	~ScavTrap();
	int HP;
	int maxHP;
	int EP;
	int maxEP;
	int lv;
	std::string name;
	int meleeAtkDmg;
	int rangedAtkDmg;
	int armorDmgReduc;
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDmg(unsigned int amount);
	// void beRepaired(unsigned int amount);
	// void vaulthunter_dot_exe(std::string const & target);
};

#endif