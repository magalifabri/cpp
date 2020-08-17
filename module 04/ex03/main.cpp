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

class ICharacter;
class AMateria;
class Ice;
class Character;
class IMateriaSource;


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


/*
 █████  ███    ███  █████  ████████ ███████ ██████  ██  █████  
██   ██ ████  ████ ██   ██    ██    ██      ██   ██ ██ ██   ██ 
███████ ██ ████ ██ ███████    ██    █████   ██████  ██ ███████ 
██   ██ ██  ██  ██ ██   ██    ██    ██      ██   ██ ██ ██   ██ 
██   ██ ██      ██ ██   ██    ██    ███████ ██   ██ ██ ██   ██ 
// -------------------------- A_MATERIA ABSTRACT CLASS -------------------------
*/


class AMateria
{
	private:
	std::string type;
	unsigned int _xp;

	public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria &materia);
	void operator=(const AMateria &materia);
	virtual ~AMateria();
	std::string const & getType() const;
	unsigned int getXP() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

	void setType(std::string const &type);
	void set_xp(unsigned int const &_xp);
};
// default constructor (coplien 1/4)
AMateria::AMateria(void)
{
	std::cout << CYAN "default constructor: AMateria\n" RESET;
	type = "void";
	_xp = 0;
}
// constructor
AMateria::AMateria(std::string const & typeParam)
{
	std::cout << CYAN "constructor: AMateria\n" RESET;
	type = typeParam;
	_xp = 0;
}
// copy constructor (coplien 2/4)
AMateria::AMateria(const AMateria &materiaParam)
{
	std::cout << CYAN "copy constructor: AMateria\n" RESET;
	operator=(materiaParam);
}
// assignment operator (coplien 3/4)
void AMateria::operator=(const AMateria &materiaParam)
{
	std::cout << CYAN "assignment operator: AMateria\n" RESET;
	type = materiaParam.getType();
	_xp = materiaParam.getXP();
}
// destructor (coplien 4/4)
AMateria::~AMateria()
{
	std::cout << MAGENTA "destructor: AMateria\n" RESET;
}

std::string const & AMateria::getType() const
{
	if (this == nullptr)
	{
		static std::string newType = "void";
		std::cout << RED "Materia doesn't have a type. Returned 'void'\n" RESET;
		return (newType);
	}
	return (type);
}
unsigned int AMateria::getXP() const
{
	return (_xp);
}
void AMateria::use(ICharacter& target)
{
	if (type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
	else if (type == "heal")
		std::cout << "* heals " << target.getName() << "'s wounds *\n";
	_xp += 10;
}

void AMateria::setType(std::string const &typeParam)
{
	type = typeParam;
}
void AMateria::set_xp(unsigned int const &_xpParam)
{
	_xp = _xpParam;
}


/*
██  ██████ ███████ 
██ ██      ██      
██ ██      █████   
██ ██      ██      
██  ██████ ███████ 
// -------------------------- ICE CLASS ---------------------------------------
*/


class Ice : public AMateria
{
	public:
	Ice();
	Ice(std::string const & type);
	~Ice();
	AMateria* clone() const;
};
// default constructor
Ice::Ice(void) : AMateria()
{
	std::cout << CYAN "default constructor: Ice\n" RESET;
	setType("ice");
}
// constructor
Ice::Ice(std::string const & typeParam) : AMateria(typeParam)
{
	std::cout << CYAN "constructor: Ice\n" RESET;
	setType(typeParam);
}
Ice::~Ice()
{
	std::cout << MAGENTA "destructor: Ice\n" RESET;
}

AMateria *Ice::clone() const
{
	AMateria *newIce = new Ice;
	newIce->setType(getType());
	newIce->set_xp(getXP());
	return (newIce);
}



class Heal : public AMateria
{
	public:
	Heal();
	Heal(std::string const & type);
	~Heal();
	AMateria* clone() const;
};
// default constructor
Heal::Heal(void) : AMateria()
{
	std::cout << CYAN "default constructor: Heal\n" RESET;
	setType("heal");
}
// constructor
Heal::Heal(std::string const & typeParam) : AMateria(typeParam)
{
	std::cout << CYAN "constructor: Heal\n" RESET;
	setType(typeParam);
}
Heal::~Heal()
{
	std::cout << MAGENTA "destructor: Heal\n" RESET;
}

AMateria *Heal::clone() const
{
	AMateria *newHeal = new Heal;
	newHeal->setType(getType());
	newHeal->set_xp(getXP());
	return (newHeal);
}


// // -------------------------- I_CHARACTER INTERFACE CLASS ----------------------


// class ICharacter
// {
// 	public:
// 	virtual ~ICharacter() {}
// 	virtual std::string const & getName() const = 0;
// 	virtual void equip(AMateria* m) = 0;
// 	virtual void unequip(int idx) = 0;
// 	virtual void use(int idx, ICharacter& target) = 0;
// };


/*
 ██████ ██   ██  █████  ██████   █████   ██████ ████████ ███████ ██████  
██      ██   ██ ██   ██ ██   ██ ██   ██ ██         ██    ██      ██   ██ 
██      ███████ ███████ ██████  ███████ ██         ██    █████   ██████  
██      ██   ██ ██   ██ ██   ██ ██   ██ ██         ██    ██      ██   ██ 
 ██████ ██   ██ ██   ██ ██   ██ ██   ██  ██████    ██    ███████ ██   ██ 
// -------------------------- CHARACTER CLASS ---------------------------------
*/


class Character : public ICharacter
{
	private:
	std::string name;

	public:
	AMateria *inventory[4];
	Character();
	Character(std::string const &name);
	Character(Character const &character);
	void operator=(Character const &character);
	~Character();
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	void printInventory();
};
// default constructor (coplien 1/4)
Character::Character(void)
{
	std::cout << CYAN "default constructor: Character\n" RESET;
}
// constructor
Character::Character(std::string const &nameParam)
{
	std::cout << CYAN "constructor: Character: " << nameParam << "\n" RESET;
	name = nameParam;
	inventory[0] = nullptr;
	inventory[1] = nullptr;
	inventory[2] = nullptr;
	inventory[3] = nullptr;
}
// copy constructor (coplien 2/4)
Character::Character(Character const &character)
{
	std::cout << CYAN "copy constructor: Character: " << character.getName() << "\n" RESET;
	operator=(character);
}
// assignment operator (coplien 3/4)
void Character::operator=(Character const &character)
{
	std::cout << CYAN "assignment operator: Character: " << character.getName() << "\n" RESET;
	
	int i;

	i = -1;
	while (++i < 4)
	{
		if (inventory[i] != nullptr)
		{
			delete inventory[i];
			inventory[i] = character.inventory[i]->clone();
		}
	}
	name = character.getName();
}
// destructor (coplien 4/4)
Character::~Character()
{
	int i;

	std::cout << MAGENTA "destructor: Character: " << name << "\n" RESET;
	i = -1;
	while (++i < 4)
	{
		if (inventory[i] != nullptr)
		{
			delete inventory[i];
			inventory[i] = nullptr;
		}
	}
}

std::string const & Character::getName() const
{
	return (name);
}
void Character::equip(AMateria* m)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (inventory[i] == m)
		{
			std::cout << RED "This exact Materia has already been equipped\n" RESET;
			return ;
		}
	}
	i = -1;
	while (++i < 4)
	{
		if (inventory[i] == nullptr)
		{
			inventory[i] = m;
			std::cout << name << " equipped " << m->getType() << " in inventory slot " << i << "\n";
			return ;
		}
	}
	std::cout << RED "cannot equip Materia " << m->getType() <<": inventory full\n" RESET;
}
void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		std::cout << RED "cannot unequip Materia: " << idx << " is an incorrect index\n" RESET;
	else if (inventory[idx] == nullptr)
		std::cout << RED "cannot unequip Materia: no Materia equipped in inventory slot" << idx << "\n" RESET;
	else
	{
		std::cout << name << " unequipped the Materia " << inventory[idx]->getType() << " from inventory slot " << idx << std::endl;
		inventory[idx] = nullptr;
	}
}
void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
		std::cout << RED "cannot use materia: incorrect index\n" RESET;
	else if (inventory[idx] == nullptr)
		std::cout << RED "cannot use materia: no materia equipped in that inventory slot\n" RESET;
	else
		inventory[idx]->use(target);
}
void Character::printInventory(void)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (inventory[i] != nullptr)
			std::cout << "equipped in inventory slot " << i << " " << inventory[i]->getType() << "\n";
	}
}


/*
███████  ██████  ██    ██ ██████   ██████ ███████ 
██      ██    ██ ██    ██ ██   ██ ██      ██      
███████ ██    ██ ██    ██ ██████  ██      █████   
     ██ ██    ██ ██    ██ ██   ██ ██      ██      
███████  ██████   ██████  ██   ██  ██████ ███████ 
// -------------------------- I_MATERIA_SOURCE INTERFACE CLASS ----------------
*/


class IMateriaSource
{
	public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
	private:
	AMateria *learnedMateria[4];

	public:
	MateriaSource();
	~MateriaSource();
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};
MateriaSource::MateriaSource(void)
{
	std::cout << CYAN "default constructor: MateriaSource\n" RESET;
	learnedMateria[0] = nullptr;
	learnedMateria[1] = nullptr;
	learnedMateria[2] = nullptr;
	learnedMateria[3] = nullptr;
}
MateriaSource::~MateriaSource(void)
{
	std::cout << MAGENTA "destructor: MateriaSource\n" RESET;
	int i = -1;
	while (++i < 4)
	{
		if (learnedMateria[i] != nullptr)
		{
			delete learnedMateria[i];
			learnedMateria[i] = nullptr;
		}
	}
}
void MateriaSource::learnMateria(AMateria *materia)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (learnedMateria[i] == materia)
		{
			std::cout << RED "This exact Materia has already been learned\n" RESET;
			return ;
		}
	}
	i = -1;
	while (++i < 4)
	{
		if (learnedMateria[i] == nullptr)
		{
			learnedMateria[i] = materia;
			std::cout << "Materia, " << materia->getType() << ", learned and stored in slot " << i << "\n";
			return ;
		}
	}
	std::cout << RED "Materia, " << materia->getType() << ", could not be learned: all storage slots used.\n"
	<< "Deleting it\n" RESET;
	delete materia;
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = -1;
	while (++i < 4)
	{
		if (learnedMateria[i] && type == learnedMateria[i]->getType())
		{
			AMateria *newMateria = learnedMateria[i]->clone();
			std::cout << "Materia of type '" << type << "' created\n";
			return (newMateria);
		}
	}
	std::cout << RED "failed to create Materia: type not amongst learned Materia\n" RESET;
	return (nullptr);
}


// -------------------------- MAIN --------------------------------------------


int main()
{
	{
		std::cout << YELLOW "\n testing Character::getName(), equip() & unequip()\n" RESET;
		
		AMateria *ice;
		ice = new Ice("ice I");
		AMateria *ice2;
		ice2 = new Ice("ice II");
		AMateria *ice3;
		ice3 = new Ice("ice III");
		AMateria *heal;
		heal = new Heal("heal I");
		AMateria *heal2;
		heal2 = new Heal("heal II");

		Character *mage;
		mage = new Character("mage");
		std::cout << "mage->getName(): " << mage->getName() << std::endl;

		mage->equip(ice);
		mage->equip(ice); // will return an error, because this particular materia instance has already been equipped
		mage->equip(ice2);
		mage->equip(ice3);
		mage->equip(heal);
		mage->equip(heal2); // will return an error, because the inventory is full
		mage->unequip(4); // will return an error, because index 4 is out of bounds
		mage->unequip(-1); // same as previous
		mage->unequip(2);
		mage->equip(heal2);
		
		delete ice3; // has to be deleted seperately, because it isn't deleted together with the rest of the materia that mage has equipped
		delete mage;
	}
	{
		std::cout << YELLOW "\n testing MateriaSource::createMateria() & learnMateria(), & Materia::getType() & clone()\n" RESET;
		
		AMateria *ice;
		ice = new Ice("ice");

		IMateriaSource *spellbook;
		spellbook = new MateriaSource();

		AMateria *created;
		created = spellbook->createMateria("ice"); // createMateria returns an error, because no Materia of type "ice" has been learned yet
		std::cout << "created->getType(): " << created->getType() << "\n"; // returns an error because AMateria *created has not been assigned an actual Materia and thus also doesn't have a type (it's currently nullptr)
		created = ice->clone(); // created is assigned a copy of AMateria *ice, so now it has a type
		std::cout << "created->getType(): " << created->getType() << "\n"; // works now
		spellbook->learnMateria(ice); // ice->clone didn't actually have spellbook learn the ice Materia, of course, but now it does learn it
		created = spellbook->createMateria("ice"); // because ice has been learned, we can use createMateria() to copy it
		spellbook->learnMateria(ice);
		spellbook->learnMateria(spellbook->createMateria("ice")); // it even works like this
		spellbook->learnMateria(spellbook->createMateria("ice"));
		spellbook->learnMateria(spellbook->createMateria("ice"));
		spellbook->learnMateria(spellbook->createMateria("ice")); // we've already learned 4 Materia, so trying to learn more returns an error

		delete spellbook;
	}
	{
		std::cout << YELLOW "\n testing Character::use()\n" RESET;
		
		// create a character
		Character *mage;
		mage = new Character("mage");

		// create something to store known spells in
		IMateriaSource *spellbook;
		spellbook = new MateriaSource();

		// create spells
		AMateria *ice;
		ice = new Ice("ice");
		AMateria *heal;
		heal = new Heal("heal");

		// store the spells in the spellbook
		spellbook->learnMateria(ice);
		spellbook->learnMateria(heal);

		// prepare the spells from the spellbook
		mage->equip(spellbook->createMateria("ice"));
		mage->equip(spellbook->createMateria("heal"));

		// create a target dummy
		ICharacter *targetDummy;
		targetDummy = new Character("target dummy");

		// attack
		std::cout << "equipped ice spell xp: " << mage->inventory[0]->getXP() << "\n";
		mage->use(0, *targetDummy);
		std::cout << "equipped ice spell xp: " << mage->inventory[0]->getXP() << "\n";
		mage->use(0, *targetDummy);
		std::cout << "equipped ice spell xp: " << mage->inventory[0]->getXP() << "\n";
		mage->use(1, *targetDummy);
		std::cout << "equipped heal spell xp: " << mage->inventory[1]->getXP() << "\n";

		// clean up
		delete mage;
		delete spellbook;
		delete targetDummy;
	}
	{
		std::cout << YELLOW "\n testing Character::operator=()\n" RESET;

		// create a character (name constructor)
		Character *mage;
		mage = new Character("mage");

		// create a spell and equip it
		AMateria *iceSpell;
		iceSpell = new Ice("ice");
		mage->equip(iceSpell);

		// create another character (copy constructor)
		Character *shapeshifter(mage);

		// check if they're the same
		std::cout << "shapeshifter->getName(): " << shapeshifter->getName() << "\n";
		shapeshifter->printInventory();
	}
	return (0);
}

/*

Description: 

AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp main.cpp

AMateria.hpp
Ice.hpp
Cure.hpp
Character.hpp
MateriaSource.hpp
ICharacter.hpp
IMateriaSource.hpp
*/