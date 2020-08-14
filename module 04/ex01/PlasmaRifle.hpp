#ifndef PLASMARIFLE_HPP
#define PLASMARIFLE_HPP

#include "AWeapon.hpp"

#include <iostream>
#include <string>

#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define REVERSED "\033[7m"

class PlasmaRifle: public AWeapon
{
	private:
	std::string name;
	int APCost;
	int dmg;

	public:
	PlasmaRifle();
	PlasmaRifle(std::string const &name, int APCost, int dmg);
	~PlasmaRifle();
	void attack() const;
};

#endif