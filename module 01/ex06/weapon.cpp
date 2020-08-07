#include "weapon.hpp"

Weapon::Weapon(std::string type)
{
	setType(type);
}

std::string Weapon::getType(void) const
{
	const std::string &reference = type;
	return (reference);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
