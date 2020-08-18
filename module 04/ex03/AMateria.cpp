#include "AMateria.hpp"

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
