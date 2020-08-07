#include <iostream>
#include <string>


// -------------------------- WEAPON CLASS ------------------------------------


class Weapon
{
public:
	Weapon();
	Weapon(std::string);
	std::string type;
	std::string getType() const;
	void setType(std::string);
};

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


// -------------------------- HUMANA CLASSES ------------------------------------


class HumanA
{
public:
	HumanA(std::string name, Weapon &wpn) : name(name), WeaponHumanA(wpn) {}
	Weapon &WeaponHumanA;
	std::string name;
	void attack();
};


void HumanA::attack(void)
{
	std::cout << name << " attacks with his " << WeaponHumanA.type << "\n";
}


// -------------------------- HUMANB CLASSES ------------------------------------


class HumanB
{
public:
	HumanB();
	HumanB(std::string);
	Weapon *WeaponHumanB;
	std::string name;
	void setWeapon(Weapon &);
	void attack();
};

HumanB::HumanB(std::string humanName)
{
	name = humanName;
}

void HumanB::setWeapon(Weapon &weaponName)
{
	WeaponHumanB = &weaponName;
}

void HumanB::attack(void)
{
	std::cout << name << " attacks with his " << WeaponHumanB->getType() << "\n";
}


// -------------------------- MAIN ------------------------------------


int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("two-handed skull-crucher");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("two-handed skull-crucher");
		jim.attack();
	}
}

// In which case is it appropriate to store the Weapon as a pointer? As a reference? Why?

// It seems to me like: References are just "simplified pointers" that are meant to take over certain jobs that pointers typically performed in C, but allow for simpler syntax. So use references when you can. The basic job that references are supposed to take over is passing a variable around that, when the value is modified anywhere, it changes everywhere. Just like you can do with a pointer, but now with cleaner looking code.

// I would argue that the weapons (weaponHumanA, weaponHumanB) should be stored as pointers, and not as references, because they should be changeable: we need to be able to say "actually, let's create a different weapon, a sword, and have them butcher each other with that instead".
// To my understanding, weaponHumanB isn't even able to be a reference. This is because a class reference member has to be initialized at class construction. But when HumanB is constructed, a Weapon isn't passed as argument to the constructor.
// For practice purposes I did create the weaponHumanA variable as a reference, since weaponHumanA is initialized at class construction.
