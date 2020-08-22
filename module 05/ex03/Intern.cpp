#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << CYAN "constructor: Intern\n" RESET;
}

Intern::~Intern(void)
{
	std::cout << MAGENTA "destructor: Intern\n" RESET;
}

Form *Intern::makeForm(std::string const &formName, std::string const &formTarget)
{
	if (formName == "" or formTarget == "")
	{
		std::cout << "Intern: 'I, uhm, feel like, uhm, I'm missing some information, uhhh..\n";
		return (nullptr);
	}

	std::string *formNames;
	formNames = new std::string[3];
	formNames[0] = "shrubbery creation";
	formNames[1] = "robotomy request";
	formNames[2] = "presidential pardon";

	Form *(*formPtrs[3])(const std::string &target);
	formPtrs[0] = ShrubberyCreationForm::getForm;
	formPtrs[1] = RobotomyRequestForm::getForm;
	formPtrs[2] = PresidentialPardonForm::getForm;

	Form *newForm;
	int i = -1;
	while (++i < 3)
	{
		if (formName == formNames[i])
			newForm = formPtrs[i](formTarget);
		else if (i == 2)
		{
			std::cout << "Intern: 'Sorry, uh, I, uhm, don't know what form you mean, sir..'\n";
			return (nullptr);
		}
	}
	std::cout << "Intern: 'Sir.. Sir.. uhm.. Here is the " << newForm->getName() << " you requested, sir..'\n";
	return (newForm);
}
