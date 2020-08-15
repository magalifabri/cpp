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


// -------------------------- I_CHARACTER INTERFACE CLASS ----------------------


class ICharacter
{
	public:
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};


// -------------------------- A_MATERIA ABSTRACT CLASS -------------------------


class AMateria
{
	private:
	std::string type;
	unsigned int _xp;
	// [...]?

	public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria &materia);
	void operator=(const AMateria &materia);
	// [...]?
	virtual ~AMateria();
	std::string const & getType() const; //Returns the materia type
	unsigned int getXP() const; //Returns the Materia's XP
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
// default constructor (coplien 1/4)
AMateria::AMateria(void)
{
	std::cout << CYAN "default constructor: AMateria\n" RESET;
}
// constructor
AMateria::AMateria(std::string const & type)
{
	std::cout << CYAN "constructor: AMateria\n" RESET;
}
// copy constructor (coplien 2/4)
AMateria::AMateria(const AMateria &materia)
{
	std::cout << CYAN "copy constructor: AMateria\n" RESET;
}
// assignment operator (coplien 3/4)
void AMateria::operator=(const AMateria &materia)
{
	std::cout << CYAN "assignment operator: AMateria\n" RESET;
}
// destructor (coplien 4/4)
AMateria::~AMateria()
{
	std::cout << MAGENTA "destructor AMateria\n" RESET;
}

std::string const & AMateria::getType() const
{
	return (type);
}
unsigned int AMateria::getXP() const
{
	return (_xp);
}
void AMateria::use(ICharacter& target)
{
	_xp += 10;
	if (type == "ice")
		std::cout << "* shoots an ice bolt at" << target.getName() << " *\n";
	else if (type == "cure")
		std::cout << "* heals" << target.getName() << "'s wounds *\n";
}


// -------------------------- ICE CLASS ---------------------------------------


class Ice : public AMateria
{
	private:
	std::string type;
	unsigned int _xp;
	// [...]?

	public:
	Ice();
	Ice(std::string const & type);
	Ice(const Ice &materia);
	void operator=(const Ice &materia);
	// [...]?
	~Ice();
	// std::string const & getType() const; //Returns the materia type
	// unsigned int getXP() const; //Returns the Materia's XP
	Ice* clone() const;
	// void use(ICharacter& target);
};
// default constructor (coplien 1/4)
Ice::Ice(void)
{
	std::cout << CYAN "default constructor: Ice\n" RESET;
	type = "ice";
	_xp = 0;
}
Ice::Ice(std::string const & typeParam)
{
	std::cout << CYAN "constructor: Ice\n" RESET;
	type = typeParam;
	_xp = 0;
}
Ice::Ice(const Ice &iceParam)
{
	std::cout << CYAN "copy constructor: Ice\n" RESET;
	operator=(iceParam);
}
void Ice::operator=(const Ice &iceParam)
{
	std::cout << CYAN "assignment operator: Ice\n" RESET;
	type = iceParam.getType();
	_xp = iceParam.getXP();
}
Ice::~Ice()
{
	std::cout << MAGENTA "destructor: Ice\n" RESET;
}
// void use(ICharacter& target)
// {

// }


// class ICharacter
// {
// 	public:
// 	virtual ~ICharacter() {}
// 	virtual std::string const & getName() const = 0;
// 	virtual void equip(AMateria* m) = 0;
// 	virtual void unequip(int idx) = 0;
// 	virtual void use(int idx, ICharacter& target) = 0;
// };


// -------------------------- CHARACTER CLASS ---------------------------------


class Character
{
	private:
	std::string name;
	AMateria *inventory[4];

	public:
	Character();
	Character(std::string const &name);
	// Character(Character const &character);
	// void operator=(Character const &character);
	~Character();
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};
// default constructor (coplien 1/4)
Character::Character(void)
{
	std::cout << CYAN "default constructor: Character\n" RESET;
}
// constructor
Character::Character(std::string const &nameParam)
{
	std::cout << CYAN "constructor: Character\n" RESET;
	name = nameParam;
	inventory[0] = nullptr;
	inventory[1] = nullptr;
	inventory[2] = nullptr;
	inventory[3] = nullptr;
}
// copy constructor (coplien 2/4)
// Character(Character const &character)
// assignment operator (coplien 3/4)
// void operator=(Character const &character)
// destructor (coplien 4/4)
Character::~Character()
{
	std::cout << MAGENTA "destructor: Character\n" RESET;
}

std::string const & Character::getName() const
{
	return (name);
}
void Character::equip(AMateria* m)
{
	if (inventory[0] == nullptr)
		inventory[0] = m;
	else if (inventory[1] == nullptr)
		inventory[1] = m;
	else if (inventory[2] == nullptr)
		inventory[2] = m;
	else if (inventory[3] == nullptr)
		inventory[3] = m;
	else
		std::cout << RED "cannot equip materia: inventory full\n" RESET;
}
void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		std::cout << RED "cannot unequip materia: incorrect index\n";
	else if (inventory[idx] == nullptr)
		std::cout << RED "cannot unequip materia: no materia equipped in that inventory slot\n" RESET;
	else
		inventory[idx] = nullptr;
}
void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
		std::cout << RED "cannot use materia: incorrect index\n";
	else if (inventory[idx] == nullptr)
		std::cout << RED "cannot use materia: no materia equipped in that inventory slot\n" RESET;
	else
		inventory[idx]->use(target);
}


// -------------------------- I_MATERIA_SOURCE INTERFACE CLASS ----------------


class IMateriaSource
{
	public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};


// -------------------------- MAIN --------------------------------------------


int main()
{
	
	return (0);
}