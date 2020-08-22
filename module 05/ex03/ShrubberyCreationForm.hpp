#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <string>
#include <iostream>
#include <exception>
#include <fstream>

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

class Bureaucrat;
class Form;

class ShrubberyCreationForm : public Form
{
private:
	std::string target;
	
public:
	ShrubberyCreationForm(std::string const &target);
	~ShrubberyCreationForm(void);
	std::string getTarget(void) {return (target);}
	void execute(Bureaucrat const &executor) const;
	static Form *getForm(std::string const &target);
};

#endif