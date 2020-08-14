#include "Enemy.hpp"

/* default constructor (coplien 1/4) */
A_Enemy::A_Enemy(void)
{
	std::cout << CYAN "Default constructor called: A_Enemy\n" RESET;
}

/* constructor */
A_Enemy::A_Enemy(int hpParam, std::string const &typeParam)
{
	std::cout << CYAN "Constructor called: A_Enemy\n" RESET;
	hp = hpParam;
	type = typeParam;
}

/* copy constructor (coplien 2/4) */
A_Enemy::A_Enemy(const A_Enemy &enemy)
{
	std::cout << CYAN "Copy constructor called: A_Enemy\n" RESET;
	operator=(enemy);
}

/* assignment operator overload (coplien 3/4) */
void A_Enemy::operator=(const A_Enemy &enemy)
{
	std::cout << CYAN "Assignment operator called: A_Enemy\n" RESET;
	hp = enemy.hp;
	type = enemy.type;
}

/* destructor (coplien 4/4) */
A_Enemy::~A_Enemy(void)
{
	std::cout << CYAN "Destructor called: A_Enemy\n" RESET;
}

std::string A_Enemy::getType() const
{
	return (type);
}

int A_Enemy::getHP() const
{
	return (hp);
}

void A_Enemy::takeDamage(int dmgAmount)
{
	if (dmgAmount < 0)
		return ;
	hp -= dmgAmount;
	std::cout << "Enemy " << type << " takes " << dmgAmount << " damage."
	<< " (" << hp << "/";
	if (type == "RadScorpion")
		std::cout << "80 HP)\n";
}
