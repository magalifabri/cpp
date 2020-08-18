#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Heal.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

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
		std::cout << YELLOW "\n testing Character::operator=() by comparing materia xp\n" RESET;

		// create a character (name constructor)
		Character *mage;
		mage = new Character("mage");

		// create a spell, equip it, show it's equipped
		AMateria *iceSpell;
		iceSpell = new Ice("ice");
		mage->equip(iceSpell);
		mage->printInventory();

		// create another character with copy constructor
		Character *shapeshifter;
		shapeshifter = new Character(*mage);

		// show the equipped spells of copy character
		std::cout << "shapeshifter->printInventory():\n";
		shapeshifter->printInventory();

		// use the spell on the first chararcter & show the xp of this spell for both characters
		mage->use(0, *shapeshifter);
		std::cout << "mage: equipped ice spell xp: " << mage->inventory[0]->getXP() << "\n";
		std::cout << "shapeshifter: equipped ice spell xp: " << shapeshifter->inventory[0]->getXP() << "\n";
		
		delete shapeshifter;
		delete mage;
	}
	return (0);
}

/*

Description
Materia are items that contain a spell. For example:
- the Materia Crystalized Snowflake contains the spell Ice
- the Materia Winterbird's Feather also contains the spell Ice
- the Materia Snowman's Effigy contains the spell Ice
- the Materia Blessed Symbol contains the spell Heal
- etc.

A character can utilize the spells contained in Materia in two ways:
- by equipping the Materia directly
*/