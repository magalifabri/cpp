#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"

int main()
{
	FragTrap fragtrap_1("fraggy");
	ScavTrap scavtrap_1("scavvy");
	NinjaTrap ninjatrap_1("ninnie");

	srand(time(NULL));
	fragtrap_1.rangedAttack("target dummy");
	// fragtrap_1.meleeAttack("target dummy");
	// fragtrap_1.takeDmg(50);
	// fragtrap_1.takeDmg(60);
	// fragtrap_1.takeDmg(10);
	// fragtrap_1.beRepaired(40);
	// fragtrap_1.beRepaired(65);
	// fragtrap_1.beRepaired(10);
	// fragtrap_1.vaulthunter_dot_exe("target dummy");
	// fragtrap_1.vaulthunter_dot_exe("target dummy");
	// fragtrap_1.vaulthunter_dot_exe("target dummy");
	// fragtrap_1.vaulthunter_dot_exe("target dummy");
	// fragtrap_1.vaulthunter_dot_exe("target dummy");
	scavtrap_1.rangedAttack("target dummy");
	// scavtrap_1.meleeAttack("target dummy");
	// scavtrap_1.takeDmg(50);
	// scavtrap_1.takeDmg(60);
	// scavtrap_1.takeDmg(10);
	// scavtrap_1.challengeNewcomer();
	// scavtrap_1.challengeNewcomer();
	// scavtrap_1.challengeNewcomer();
	// scavtrap_1.challengeNewcomer();
	// scavtrap_1.challengeNewcomer();
	ninjatrap_1.ninjaShoebox(ninjatrap_1);
	ninjatrap_1.ninjaShoebox(fragtrap_1);
	ninjatrap_1.ninjaShoebox(scavtrap_1);
}