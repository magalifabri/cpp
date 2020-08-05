#include "Zombie.hpp"

Zombie::Zombie(void)
{
	// std::cout << "constructor called\n";
}
Zombie::~Zombie(void)
{
	// std::cout << "destructor called\n";
}

void Zombie::announce(void)
{
	std::cout << "< " << this->type << " (" << this->name << ") > : '" << get_growl() << ".. " << this->name << "! Brains, please.'\n";
}