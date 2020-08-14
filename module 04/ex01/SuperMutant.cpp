#include "SuperMutant.hpp"

/* constructor */
SuperMutant::SuperMutant(int hpParam, std::string typeParam)
: A_Enemy(hpParam, typeParam)
{
	std::cout << CYAN "Gaaah. Me want smash heads!\n" RESET;
	hp = hpParam;
	type = typeParam;
}

/* destructor */
SuperMutant::~SuperMutant(void)
{
	std::cout << CYAN "Aaargh...\n" RESET;
}

void SuperMutant::takeDamage(int dmgAmount)
{
	if (dmgAmount < 0)
		return ;
	hp -= (dmgAmount - 3);
	std::cout << "Enemy " << type << " takes " << dmgAmount - 3 << " damage."
	<< " (" << hp << "/" << "170 HP)\n";
	if (hp <= 0)
		SuperMutant::~SuperMutant();
}
