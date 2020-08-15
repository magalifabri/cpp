#include "ISpaceMarine.hpp"
#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"

#include <string>
#include <iostream>

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
	std::cout << CYAN "constructors are cyan\n" MAGENTA "destructors are magenta\n\n" RESET;


	std::cout << YELLOW "create Valiant Lion Crusaders squad" RESET;
	Squad *VLC;
	ISpaceMarine *bobTM;
	ISpaceMarine *jimAT;

	VLC = new Squad;
	bobTM = new TacticalMarine();
	jimAT = new AssaultTerminator();


	std::cout << YELLOW "\ntest getCount() & push()\n" RESET;
	std::cout << "return of getCount(): " << VLC->getCount() << std::endl;
	std::cout << "return of push(bobTM): " << VLC->push(bobTM) << std::endl;
	std::cout << "return of getCount(): " << VLC->getCount() << std::endl;
	std::cout << "return of push(jimAT): " << VLC->push(jimAT) << std::endl;
	std::cout << "return of getCount(): " << VLC->getCount() << std::endl;


	std::cout << YELLOW "\ntest VLC squad & marine abilities\n" RESET;
	ISpaceMarine *cur;
	int i = -1;
	while (++i < VLC->getCount() + 1)
	{
		cur = VLC->getUnit(i);
		if (cur == nullptr)
			break ;
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
		std::cout << std::endl;
	}


	std::cout << YELLOW "\ncreate Chaos Legion Platoon squad as copy of VLC & add marine to CLP\n" RESET;
	Squad CLP(*VLC);
	ISpaceMarine *myr;
	myr = new TacticalMarine;
	CLP.push(myr);


	std::cout << YELLOW "\ndelete VLC squad units & VLC squad\n" RESET;
	i = -1;
	while (++i < VLC->getCount())
		delete VLC->getUnit(i);
	delete VLC;


	std::cout << YELLOW "\ntest CLP squad (copy of VLC + TacticalMarine) & marine abilities\n" RESET;
	i = -1;
	while (++i < CLP.getCount() + 1)
	{
		cur = CLP.getUnit(i);
		if (cur == nullptr)
			break ;
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
		std::cout << std::endl;
	}


	std::cout << YELLOW "\ndelete CLP squad units\n" RESET;
	i = -1;
	while (++i < CLP.getCount())
		delete CLP.getUnit(i);
	
	return (0);
}

/*
clang++ -Wall -Wextra -Werror main.cpp AssaultTerminator.cpp Squad.cpp TacticalMarine.cpp && ./a.out 
*/