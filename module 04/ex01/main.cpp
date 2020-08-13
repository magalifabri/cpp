#include <iostream>
#include <string>


/* -------------------------- AWEAPON ABSTRACT BASE CLASS ------------------ */

class AWeapon
{
	private:
	
	public:
	std::string name;
	int APCost;
	int dmg;
	AWeapon();
	AWeapon(std::string const &name, int APCost, int dmg);
	AWeapon(const AWeapon &weapon);
	virtual ~AWeapon();
	void operator=(const AWeapon &);
	std::string virtual getName() const;
	int getAPCost() const;
	int getDmg() const;
	virtual void attack() const = 0;
};
AWeapon::AWeapon(void)
{
	std::cout << "Default constructor called: AWeapon\n";
}
AWeapon::AWeapon(std::string const &weaponName, int weaponAPCost, int weaponDmg)
{
	std::cout << "Constructor called: AWeapon\n";
	name = weaponName;
	APCost = weaponAPCost;
	dmg = weaponDmg;
}
AWeapon::AWeapon(const AWeapon &weapon)
{
	std::cout << "Copy constructor called\n";
	operator=(weapon);
}
void AWeapon::operator=(const AWeapon &weapon)
{
	std::cout << "Assignation operator called\n";
	name = weapon.name;
	APCost = weapon.APCost;
	dmg = weapon.dmg;
}
AWeapon::~AWeapon()
{
	std::cout << "Destructor called: AWeapon\n";
}
std::string AWeapon::getName() const
{
	return (name);
}
int AWeapon::getAPCost() const
{
	return (APCost);
}
int AWeapon::getDmg() const
{
	return (dmg);
}
// virtual void AWeapon::attack() const = 0
// {

// }


/* -------------------------- PLASMARIFLE CLASS ---------------------------- */


class PlasmaRifle: public AWeapon
{
	public:
	PlasmaRifle();
	~PlasmaRifle();
	void attack() const;
};
PlasmaRifle::PlasmaRifle(void) : AWeapon()
{
	std::cout << "Constructor called: PlasmaRifle\n";
	name = "PlasmaRifle";
	dmg = 21;
	APCost = 5;
}
PlasmaRifle::~PlasmaRifle(void)
{
	std::cout << "Destructor called: PlasmaRifle\n";
}
void PlasmaRifle::attack(void) const
{
	std::cout << "* piouuu piouuu piouuu *";
}


/* -------------------------- POWER FIRST CLASS ---------------------------- */


class PowerFist: public AWeapon
{
	public:
	PowerFist();
	~PowerFist();
	void attack() const;
};
PowerFist::PowerFist(void) : AWeapon()
{
	std::cout << "Constructor called: PowerFist\n";
	name = "PowerFist";
	dmg = 50;
	APCost = 8;
}
PowerFist::~PowerFist(void)
{
	std::cout << "Destructor called: PowerFist\n";
}
void PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *";
}


/* -------------------------- ENEMY ----------------------------------------- */


// class Enemy
// {
// 	private:
// 	// [...]
// 	public:
// 	Enemy(int hp, std::string const & type);
// 	virtual ~Enemy();
// 	std::string virtual getType() const;
// 	int getHP() const;
// 	virtual void takeDamage(int);
// };


/* -------------------------- MAIN ----------------------------------------- */



int main()
{
	PlasmaRifle testGun;
	PowerFist testPowerFist;
}