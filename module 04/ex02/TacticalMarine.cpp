#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
	std::cout << CYAN "TacticalMarine: 'Tactical Marine ready for battle!'\n" RESET;
}
TacticalMarine::~TacticalMarine()
{
	std::cout << MAGENTA "TacticalMarine: 'Aaargh...'\n" RESET;
}

ISpaceMarine *TacticalMarine::clone(void) const
{
	std::cout << "TacticalMarine::clone(): * Cloning Tactical Marine... *\n";
	ISpaceMarine *clone;
	clone = new TacticalMarine();
	return (clone);
}
void TacticalMarine::battleCry() const
{
	std::cout << "TacticalMarine::battleCry(): 'For the holy PLOT!'\n";
}
void TacticalMarine::rangedAttack() const
{
	std::cout << "TacticalMarine::rangedAttack(): * attacks with a bolter *\n";
}
void TacticalMarine::meleeAttack() const
{
	std::cout << "TacticalMarine::meleeAttack(): * attacks with a chainsword *\n";
}
