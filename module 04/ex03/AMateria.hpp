#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"

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

#endif