#include "Pony.hpp"

Pony::Pony(void)
{
	std::cout << "constructor called: a pony is born!\n";
	return ;
}

Pony::~Pony(void)
{
	std::cout << "destructor called: " << this->name << " died.\n";
	return ;
}

void Pony::eat(void)
{
	std::cout << this->name << " is eating.\n";
}

void Pony::shit(void)
{
	std::cout << this->name << " is thinking. Oh, wait, no. It's just shitting.\n";
}

void Pony::sleep(void)
{
	std::cout << this->name << " is sleeping.\n";
}
