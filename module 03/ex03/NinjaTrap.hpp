#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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

class NinjaTrap : public ClapTrap
{
	public:
	NinjaTrap(std::string NinjaTrapName);
	~NinjaTrap();
	void ninjaShoebox(NinjaTrap &);
	void ninjaShoebox(ScavTrap &);
	void ninjaShoebox(FragTrap &);
};

#endif