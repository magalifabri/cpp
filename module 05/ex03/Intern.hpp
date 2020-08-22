#ifndef INTERN_HPP
#define INTERN_HPP

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

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <string>
#include <iostream>
#include <exception>

class Form;

class Intern
{
public:
	Intern(void);
	~Intern(void);
	Form *makeForm(std::string const &formName, std::string const &formTarget);
};

#endif