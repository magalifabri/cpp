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


// -------------------------- SPACE MARINE INTERFACE --------------------------


class ISpaceMarine
{
	public:
	virtual ~ISpaceMarine() {}
	virtual ISpaceMarine* clone() const = 0;
	virtual void battleCry() const = 0;
	virtual void rangedAttack() const = 0;
	virtual void meleeAttack() const = 0;
};


// -------------------------- TACTICAL MARINE CLASS ---------------------------


class TacticalMarine : public ISpaceMarine
{
	public:
	TacticalMarine();
	~TacticalMarine();
	ISpaceMarine* clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
};
TacticalMarine::TacticalMarine()
{
	std::cout << CYAN "Tactical Marine ready for battle!\n" RESET;
}
TacticalMarine::~TacticalMarine()
{
	std::cout << MAGENTA "Aaargh...\n" RESET;
}

ISpaceMarine *TacticalMarine::clone(void) const
{
	std::cout << "\n";
	ISpaceMarine *clone;
	clone = new TacticalMarine();
	return (clone);
}
void TacticalMarine::battleCry() const
{
	std::cout << "For the holy PLOT!\n";
}
void TacticalMarine::rangedAttack() const
{
	std::cout << "* attacks with a bolter *\n";
}
void TacticalMarine::meleeAttack() const
{
	std::cout << "* attacks with a chainsword *\n";
}


// -------------------------- ASSAULT TERMINATOR CLASS ------------------------


class AssaultTerminator : public ISpaceMarine
{
	public:
	AssaultTerminator();
	~AssaultTerminator();
	ISpaceMarine* clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
};
AssaultTerminator::AssaultTerminator()
{
	std::cout << CYAN "* teleports from space *\n" RESET;
}
AssaultTerminator::~AssaultTerminator()
{
	std::cout << MAGENTA "I’ll be back...\n" RESET;
}

ISpaceMarine *AssaultTerminator::clone(void) const
{
	std::cout << "\n";
	ISpaceMarine *clone;
	clone = new AssaultTerminator();
	return (clone);
}
void AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. PURIFY IT!\n";
}
void AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *\n";
}
void AssaultTerminator::meleeAttack() const
{
	std::cout << "* attacks with chainfists *\n";
}


// -------------------------- ISQUAD INTERFACE --------------------------------


class ISquad
{
	public:
	virtual ~ISquad() {}
	virtual int getCount() const = 0;
	virtual ISpaceMarine* getUnit(int) const = 0;
	virtual int push(ISpaceMarine*) = 0;
};


// -------------------------- SQUAD CLASS -------------------------------------


class Squad : public ISquad
{
	private:
	ISpaceMarine *squadmembers[12];

	public:
	Squad();
	Squad(Squad const &squad);
	void operator=(Squad const &squad);
	~Squad();
	int getCount() const;
	ISpaceMarine* getUnit(int) const;
	int push(ISpaceMarine*);
};
Squad::Squad(void)
{
	std::cout << CYAN "Constructor called: Squad\n" RESET;
	squadmembers[0] = nullptr;
}
Squad::Squad(Squad const &squad)
{
	std::cout << CYAN "Copy constructor called: Squad\n" RESET;
	operator=(squad);
}
void Squad::operator=(Squad const &squad)
{
	int i = -1;
	while (squadmembers[++i])
	{
		delete squadmembers[i];
	}
	i = -1;
	while (squad.squadmembers[++i])
	{
		squadmembers[i] = squad.squadmembers[i];
	}
}
Squad::~Squad(void)
{
	std::cout << MAGENTA "Destructor called: Squad\n" RESET;
}
int Squad::getCount() const
{
	int i;

	i = 0;
	while (squadmembers[i])
		i++;
	return (i);
}
ISpaceMarine* Squad::getUnit(int squadmemberIndex) const
{
	if (squadmemberIndex >= getCount())
	{
		std::cout << "getUnit(): error: out of bounds index\n";
		return (nullptr);
	}
	return (squadmembers[squadmemberIndex]);
}
// go to the end of the array and add a new pointer
int Squad::push(ISpaceMarine *marine)
{
	int i;

	i = 0;
	while (squadmembers[i])
		i++;
	squadmembers[i] = marine;
	squadmembers[++i] = nullptr;
	return (i);
}


// -------------------------- MAIN --------------------------------------------


int main()
{
	// CREATE vlc squad
	ISquad *vlc;
	ISpaceMarine *bob;
	ISpaceMarine *jim;

	vlc = new Squad;
	bob = new TacticalMarine();
	jim = new AssaultTerminator();

	std::cout << "return of getCount(): " << vlc->getCount() << std::endl;
	std::cout << "return of push(bob): " << vlc->push(bob) << std::endl;
	std::cout << "return of getCount(): " << vlc->getCount() << std::endl;
	std::cout << "return of push(jim): " << vlc->push(jim) << std::endl;
	std::cout << "return of getCount(): " << vlc->getCount() << std::endl;

	// TEST VLC SQUAD
	ISpaceMarine *cur;
	int i;

	i = -1;
	while (++i < vlc->getCount() + 1)
	{
		cur = vlc->getUnit(i);
		if (cur == nullptr)
			break ;
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}


	// DELETE marines in vlc squad
	i = -1;
	while (++i < vlc->getCount())
	{
		delete vlc->getUnit(i);
	}
	// delete bob;
	// delete jim;
	delete vlc;
	return (0);
}