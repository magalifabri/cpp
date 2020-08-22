#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &targetParam)
{
	std::cout << CYAN "constructor: RobotomyRequestForm with target: " << targetParam << "\n" RESET;
	target = targetParam;
	setName("Robotomy Request Form");
	setGradeNeededToSign(72);
	setGradeNeededToExecute(45);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << MAGENTA "destructor: RobotomyRequestForm\n" RESET;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	std::cout << executor.getName() << ": 'Checking if form is signed..'\n";
	if (getSignedStatus() == 1)
		std::cout << executor.getName() << ": 'Affirmative! Good job, boy.' * pats you on the head *\n";
	else
	{
		std::cout << executor.getName() << ": 'Negative! Beat it, scrub!'\n";
		return ;
	}
	
	std::cout << executor.getName() << ": 'Checking if I can execute on this form..'\n";
	if (executor.getGrade() <= getGradeNeededToExecute())
		std::cout << executor.getName() << ": 'Affirmative! Yeey me!'\n";
	else
	{
		std::cout << executor.getName() << ": 'Negative.. FML, I never get to do anything!' * stamps foot *\n";
		return ;
	}

	std::cout << executor.getName() << ": Alriiiight, here we go!\n"
	<< executor.getName() << ": 'Drill, please'\n"
	<< "* wzzzzzz wzzz wzzz *\n"
	<< executor.getName() << ": 'Even bigger drill, please'\n"
	<< "* BRRR brrrrr BRRRRRRRR *\n"
	<< executor.getName() << ": 'Jackhammer, please'\n"
	<< "* THUD THUD THUD THUD *\n"
	<< executor.getName() << ": 'Fire extinguisher, please!'\n"
	<< "* shggggggg *\n";

	if (rand() % 2 == 1)
	{
		std::cout << executor.getName() << ": 'The Robotomy on " << target << " was entirely, a 100% successfull.. Yup, absolutely nothing went wrong at all!'\n";
	}
	else
	{
		std::cout << executor.getName() << ": 'I regret to inform you that " << target << " caught fire and burnt down.. Sorry! kthxbye\n";
	}
}

Form *RobotomyRequestForm::getForm(std::string const &target)
{
	Form *newForm;
	newForm = new RobotomyRequestForm(target);
	return (newForm);
}
