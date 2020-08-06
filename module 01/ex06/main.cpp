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

// -------------------------- WEAPON CLASS ------------------------------------

// Make a Weapon class, that has a type string, and a getType that returns a const reference to this string. Also has a setType
class Weapon
{
public:
	Weapon();
	Weapon(std::string);
	std::string type;
	std::string *getType() const;
	void setType(std::string);
};
// default constructor
Weapon::Weapon(void)
{
	std::cout << BLUE "Weapon default constructor() called\n" RESET;
}
// constructor overload with string parameter
Weapon::Weapon(std::string type)
{
	std::cout << BLUE "Weapon constructor(std::string) called\n" RESET;
	setType(type);
}

std::string *Weapon::getType(void) const
{
}

void Weapon::setType(std::string type)
{
	this->type = type;
}


// -------------------------- HUMANA CLASSES ------------------------------------


// Now, create two classes, HumanA and HumanB, that both have a Weapon, a name, and an attack() function that displays something like: NAME attacks with his WEAPON_TYPE
class HumanA
{
public:
	HumanA();
	HumanA(std::string, Weapon &);
	Weapon *WeaponHumanA;
	std::string name;
	void attack();
};
HumanA::HumanA(void)
{
	std::cout << BLUE "HumanA default constructor() called\n" RESET;
}
// "Weapon &weaponName" parameter so that the function isn't passed a copy of the weapon, but references the actual weapon itself.
// "WeaponHumanA = &weaponName" variable assignment so that WeaponHumanA points to the value of weaponName and doesn't just copy it's value.
// These two things are required for WeaponHumanA to also change when the instance of the Weapon itself is changed.
HumanA::HumanA(std::string humanName, Weapon &weaponName)
{
	std::cout << BLUE "HumanA constructor(string, Weapon) called\n" RESET;
	name = humanName;
	WeaponHumanA = &weaponName;
}

void HumanA::attack(void)
{
	std::cout << name << " attacks with his " << WeaponHumanA->type << "\n";
}


// -------------------------- HUMANB CLASSES ------------------------------------


// Now, create two classes, HumanA and HumanB, that both have a Weapon, a name, and an attack() function that displays something like: NAME attacks with his WEAPON_TYPE
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
HumanB::HumanB(void)
{
	std::cout << BLUE "HumanB default constructor() called\n" RESET;
}
// "Weapon &weaponName" parameter so that the function isn't passed a copy of the weapon, but references the actual weapon itself.
// "WeaponHumanB = &weaponName" variable assignment so that WeaponHumanB points to the value of weaponName and doesn't just copy it's value.
// These two things are required for WeaponHumanB to also change when the instance of the Weapon itself is changed.
HumanB::HumanB(std::string humanName)
{
	std::cout << BLUE "HumanB constructor(string) called\n" RESET;
	name = humanName;
}

void HumanB::setWeapon(Weapon &weaponName)
{
	WeaponHumanB = &weaponName;
}

void HumanB::attack(void)
{
	std::cout << name << " attacks with his " << WeaponHumanB->type << "\n";
}


// -------------------------- MAIN ------------------------------------


// Make it so the following code produces attacks with "crude spiked club" THEN "some other type of club", in both test cases:
int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}