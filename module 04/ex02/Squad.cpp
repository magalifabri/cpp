#include "Squad.hpp"

Squad::Squad(void)
{
	std::cout << CYAN "Constructor called: Squad\n" RESET;
	squadmembers[0] = nullptr;
}
Squad::Squad(Squad const &squad)
{
	std::cout << CYAN "Copy constructor called: Squad\n" RESET;
	operator=(squad);
}
void Squad::operator=(Squad const &squad)
{
	int i;
	
	std::cout << CYAN "Assignment operator called: Squad\n" RESET;
	i = -1;
	while (squadmembers[++i])
		delete squadmembers[i];
	i = -1;
	while (squad.squadmembers[++i])
		squadmembers[i] = squad.squadmembers[i]->clone();
}
Squad::~Squad(void)
{
	std::cout << MAGENTA "Destructor called: Squad\n" RESET;
}
int Squad::getCount() const
{
	int i;

	i = 0;
	while (squadmembers[i])
		i++;
	return (i);
}
ISpaceMarine* Squad::getUnit(int squadmemberIndex) const
{
	if (squadmemberIndex >= getCount())
	{
		std::cout << RED "getUnit(): error: out of bounds index\n" RESET;
		return (nullptr);
	}
	return (squadmembers[squadmemberIndex]);
}
// go to the end of the array and add a new pointer
int Squad::push(ISpaceMarine *marine)
{
	int i;

	i = 0;
	while (squadmembers[i])
		i++;
	squadmembers[i] = marine;
	squadmembers[++i] = nullptr;
	return (i);
}
