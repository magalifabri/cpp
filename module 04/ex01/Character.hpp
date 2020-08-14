#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AWeapon.hpp"
#include "Enemy.hpp"

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

#endif