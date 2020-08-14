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


/* -------------------------- AWEAPON ABSTRACT BASE CLASS ------------------ */

class AWeapon
{
	private:
	std::string name;
	int APCost;
	int dmg;
	
	public:
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

/* default constructor (coplien 1/4) */
AWeapon::AWeapon(void)
{
	std::cout << CYAN "Default constructor called: AWeapon\n" RESET;
}

/* constructor */
AWeapon::AWeapon(std::string const &nameParam, int APCostParam, int dmgParam)
{
	std::cout << CYAN "Constructor called: AWeapon\n" RESET;
	name = nameParam;
	APCost = APCostParam;
	dmg = dmgParam;
}

/* copy constructor (coplien 2/4) */
AWeapon::AWeapon(const AWeapon &weapon)
{
	std::cout << CYAN "Copy constructor called\n" RESET;
	operator=(weapon);
}

/* assignment operator overload (coplien 3/4) */
void AWeapon::operator=(const AWeapon &weapon)
{
	std::cout << CYAN "Assignation operator called\n" RESET;
	name = weapon.name;
	APCost = weapon.APCost;
	dmg = weapon.dmg;
}

/* destructor (coplien 4/4) */
AWeapon::~AWeapon()
{
	std::cout << CYAN "Destructor called: AWeapon\n" RESET;
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


/* -------------------------- PLASMARIFLE CLASS ---------------------------- */


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

/* default constructor */
PlasmaRifle::PlasmaRifle(void) : AWeapon()
{
	std::cout << CYAN "Default constructor called: PlasmaRifle\n" RESET;
}

/* constructor */
PlasmaRifle::PlasmaRifle(std::string const &nameParam, int APCostParam
, int dmgParam) : AWeapon(nameParam, APCostParam, dmgParam)
{
	std::cout << CYAN "Constructor called: PlasmaRifle\n" RESET;
	name = nameParam;
	APCost = APCostParam;
	dmg = dmgParam;
}

/* destructor */
PlasmaRifle::~PlasmaRifle(void)
{
	std::cout << CYAN "Destructor called: PlasmaRifle\n" RESET;
}

void PlasmaRifle::attack(void) const
{
	std::cout << "* piouuu piouuu piouuu *\n";
}


/* -------------------------- POWERFIST CLASS ------------------------------ */


class PowerFist: public AWeapon
{
	private:
	std::string name;
	int APCost;
	int dmg;

	public:
	PowerFist();
	PowerFist(std::string name, int APCost, int dmg);
	~PowerFist();
	void attack() const;
};

/* default constructor */
PowerFist::PowerFist(void) : AWeapon()
{
	std::cout << CYAN "Default constructor called: PowerFist\n" RESET;
}

/* constructor */
PowerFist::PowerFist(std::string wpnName, int wpnAPCost, int wpnDmg)
: AWeapon(wpnName, wpnAPCost, wpnDmg)
{
	std::cout << CYAN "Constructor called: PowerFist\n" RESET;
	name = wpnName;
	APCost = wpnAPCost;
	dmg = wpnDmg;
}

/* destructor */
PowerFist::~PowerFist(void)
{
	std::cout << CYAN "Destructor called: PowerFist\n" RESET;
}

void PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *\n";
}


/* -------------------------- ENEMY ----------------------------------------- */


class A_Enemy
{
	private:
	int hp;
	std::string type;

	public:
	A_Enemy();
	A_Enemy(int hp, std::string const &type);
	A_Enemy(const A_Enemy &enemy);
	void operator=(const A_Enemy &enemy);
	virtual ~A_Enemy();
	std::string virtual getType() const;
	int getHP() const;
	virtual void takeDamage(int);
};

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


/* -------------------------- SUPERMUTANT ---------------------------------- */


class SuperMutant : public A_Enemy
{
	private:
	int hp;
	std::string type;

	public:
	SuperMutant(int hp, std::string type);
	~SuperMutant();
	void takeDamage(int dmgAmount);
};

/* constructor */
SuperMutant::SuperMutant(int hpParam, std::string typeParam)
: A_Enemy(hpParam, typeParam)
{
	std::cout << CYAN "Gaaah. Me want smash heads!\n" RESET;
	hp = hpParam;
	type = typeParam;
}

/* destructor */
SuperMutant::~SuperMutant(void)
{
	std::cout << CYAN "Aaargh...\n" RESET;
}

void SuperMutant::takeDamage(int dmgAmount)
{
	if (dmgAmount < 0)
		return ;
	hp -= (dmgAmount - 3);
	std::cout << "Enemy " << type << " takes " << dmgAmount - 3 << " damage."
	<< " (" << hp << "/" << "170 HP)\n";
	if (hp <= 0)
		SuperMutant::~SuperMutant();
}


/* -------------------------- RADSCORPION ---------------------------------- */


class RadScorpion : public A_Enemy
{
	private:
	int hp;
	std::string type;

	public:
	RadScorpion(int hp, std::string type);
	~RadScorpion();
};

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


/* -------------------------- CHARACTER ----------------------------------------- */


class Character
{
	private:
	std::string name;
	int AP;
	int maxAP;
	AWeapon *weapon;

	public:
	Character();
	Character(std::string const & name);
	Character(Character const &character);
	~Character();
	void operator=(Character const &character);
	void recoverAP();
	void equip(AWeapon*);
	void attack(A_Enemy*);
	std::string virtual getName() const;
	int getAP() const;
	std::string getWeaponType() const;
};

/* default constructor (coplien 1/4) */
Character::Character()
{
	std:: cout << CYAN "Default constructor called: Character\n" RESET;
}

/* constructor */
Character::Character(std::string const &nameParam)
{
	std:: cout << CYAN "Constructor called: Character\n" RESET;
	name = nameParam;
	AP = 40;
	maxAP = 40;
	weapon = nullptr;
}

/* copy constructor (coplien 2/4) */
Character::Character(Character const &character)
{
	std:: cout << CYAN "Copy constructor called: Character\n" RESET;
	operator=(character);
}

/* assignment operator overload (coplien 3/4) */
void Character::operator=(Character const &character)
{
	std:: cout << CYAN "Assignment Operator called: Character\n" RESET;
	name = character.getName();
	AP = character.AP;
	maxAP = 40;
	weapon = character.weapon;
}

/* destructor (coplien 4/4) */
Character::~Character()
{
	std:: cout << CYAN "Destructor called: Character\n" RESET;
}

void Character::recoverAP()
{
	AP += 10;
	if (AP > maxAP)
		AP = maxAP;
	std::cout << name << " restored 10 AP. (" << AP << "/40 AP)\n";
}

void Character::equip(AWeapon* weaponParam)
{
	weapon = weaponParam;
	std::cout << name << " equipped " << weapon->getName() << ".\n";
}

void Character::attack(A_Enemy *enemy)
{
	if (weapon == nullptr)
	{
		std::cout << RED "Can't attack: no weapon equipped.\n" RESET;
		return ;
	}
	if (AP - weapon->getAPCost() < 0)
	{
		std::cout << RED "Can't attack: not enough AP. ("
		<< AP << "/40 AP)\n" RESET;
		return ;
	}
	std::cout << name << " attacks " << enemy->getType() << " with a "
	<< weapon->getName() << ".\n";
	weapon->attack();
	enemy->takeDamage(weapon->getDmg());
	AP -= weapon->getAPCost();
	if (enemy->getHP() <= 0)
		enemy->~A_Enemy();
}

std::string Character::getName() const
{
	return (name);
}

int Character::getAP() const
{
	return (AP);
}

std::string Character::getWeaponType() const
{
	if (weapon == nullptr)
		return ("");
	return (weapon->getName());
}


/* -------------------------- MAIN ----------------------------------------- */


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
