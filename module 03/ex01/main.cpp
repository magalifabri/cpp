#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	FragTrap claptrap_1("clappy");
	ScavTrap scavtrap_1("scavvy");

	srand(time(NULL));
	claptrap_1.rangedAttack("target dummy");
	claptrap_1.meleeAttack("target dummy");
	claptrap_1.takeDmg(50);
	claptrap_1.takeDmg(60);
	claptrap_1.takeDmg(10);
	claptrap_1.beRepaired(40);
	claptrap_1.beRepaired(65);
	claptrap_1.beRepaired(10);
	claptrap_1.vaulthunter_dot_exe("target dummy");
	claptrap_1.vaulthunter_dot_exe("target dummy");
	claptrap_1.vaulthunter_dot_exe("target dummy");
	claptrap_1.vaulthunter_dot_exe("target dummy");
	claptrap_1.vaulthunter_dot_exe("target dummy");
	scavtrap_1.rangedAttack("target dummy");
	scavtrap_1.meleeAttack("target dummy");
	scavtrap_1.takeDmg(50);
	scavtrap_1.takeDmg(60);
	scavtrap_1.takeDmg(10);
}