#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &targetParam)
{
	std::cout << CYAN "constructor: PresidentialPardonForm with target: " << targetParam << "\n" RESET;
	target = targetParam;
	setName("Presidential Pardon Form");
	setGradeNeededToSign(145);
	setGradeNeededToExecute(137);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << MAGENTA "destructor: PresidentialPardonForm\n" RESET;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	std::cout << executor.getName() << ": 'Checking if form is signed..'\n";
	if (getSignedStatus() == 1)
		std::cout << executor.getName() << ": 'Affirmative! Good job, boy.' * pats you on the head *\n";
	else
	{
		std::cout << executor.getName() << ": 'Negative! Beat it, scrub!'\n";
		return ;
	}
	
	std::cout << executor.getName() << ": '" << target << " has been pardoned by Zafod Beeblebrox!'\n";
}