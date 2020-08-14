#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"

#include <iostream>
#include <string>

std::ostream &operator<<(std::ostream &os, const Character *character)
{
	if (character->getWeaponType() == "")
	{
		os << character->getName() << " has " << character->getAP()
		<< " AP and is unarmed.\n";
	}
	else
	{
		os << character->getName() << " has " << character->getAP()
		<< " AP and wields a " << character->getWeaponType() << ".\n";
	}
	return (os);
}

int main()
{
	AWeapon *pioupiou;
	AWeapon *bambam;
	A_Enemy *grun;
	A_Enemy *clicky;
	Character *bill;

	pioupiou = new PlasmaRifle("PlasmaRifle", 5, 21);
	bambam = new PowerFist("PowerFist", 8, 50);
	grun = new SuperMutant(170, "Super Mutant");
	clicky = new RadScorpion(80, "RadScorpion");
	bill = new Character("Bill");
	std::cout << bill;
	bill->attack(grun);
	bill->equip(bambam);
	bill->attack(grun);
	std::cout << bill;
	bill->attack(grun);
	bill->attack(grun);
	bill->attack(grun);
	bill->equip(pioupiou);
	bill->attack(clicky);
	bill->attack(clicky);
	bill->recoverAP();
	bill->recoverAP();
	bill->attack(clicky);
	bill->attack(clicky);
	bill->attack(clicky);
	std::cout << "ding!\n";
	bill->Character::~Character();
	pioupiou->~AWeapon();
	bambam->~AWeapon();
}
