#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
	std::cout << CYAN "AssaultTerminator: * teleports from space *\n" RESET;
}
AssaultTerminator::~AssaultTerminator()
{
	std::cout << MAGENTA "AssaultTerminator: 'I’ll be back...'\n" RESET;
}

ISpaceMarine *AssaultTerminator::clone(void) const
{
	std::cout << "AssaultTerminator::clone(): * Cloning Assault Terminator... *\n";
	ISpaceMarine *clone;
	clone = new AssaultTerminator();
	return (clone);
}
void AssaultTerminator::battleCry() const
{
	std::cout << "AssaultTerminator::battleCry(): 'This code is unclean. PURIFY IT!'\n";
}
void AssaultTerminator::rangedAttack() const
{
	std::cout << "AssaultTerminator::rangedAttack(): * does nothing *\n";
}
void AssaultTerminator::meleeAttack() const
{
	std::cout << "AssaultTerminator::meleeAttack(): * attacks with chainfists *\n";
}
