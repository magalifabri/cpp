#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

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

class Character : public ICharacter
{
	private:
	std::string name;

	public:
	AMateria *inventory[4];
	Character();
	Character(std::string const &name);
	Character(const Character &character);
	void operator=(const Character &character);
	~Character();
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	void printInventory();
};

#endif