#include "RadScorpion.hpp"

/* constructor */
RadScorpion::RadScorpion(int hpParam, std::string typeParam)
: A_Enemy(hpParam, typeParam)
{
	std::cout << CYAN "* click click click *\n" RESET;
	hp = hpParam;
	type = typeParam;
}

/* destructor */
RadScorpion::~RadScorpion(void)
{
	std::cout << CYAN "* SPROTCH *\n" RESET;
}
