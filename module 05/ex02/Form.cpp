#include "Form.hpp"

Form::Form(void)
{
	std::cout << CYAN "default constructor: Form\n" RESET;
	signedStatus = 0;
}

Form::Form(std::string const &nameParam, int const &gradeNeededToSignParam, int const &gradeNeededToExecuteParam)
{
	std::cout << CYAN "constructor: Form: " << nameParam << "\n" RESET;
	name = nameParam;
	signedStatus = 0;
	gradeNeededToSign = gradeNeededToSignParam;
	gradeNeededToExecute = gradeNeededToExecuteParam;
}

Form::~Form(void)
{
	std::cout << MAGENTA "destructor: Form: " << name << "\n" RESET;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() > gradeNeededToSign)
			throw tooLow;
		std::cout << bureaucrat.getName() << " signs form '" << name << "'\n" << bureaucrat.getName() << ": 'Time for a well-deserved break!'\n";
		signedStatus = 1;
	}
	catch(const std::exception& exception)
	{
		std::cout << exception.what() << "\n";
		GradeTooLowException(bureaucrat);
	}
}

void Form::GradeTooHighException(Bureaucrat const &bureaucrat)
{
	std::cout << bureaucrat.getName() << " can't sign form '" << name << "', because his grade is too.. high..? What?";
}

void Form::GradeTooLowException(Bureaucrat const &bureaucrat)
{
	std::cout << bureaucrat.getName() << " can't sign form '" << name << "', because he has grade " << bureaucrat.getGrade() << ", but needs grade " << gradeNeededToSign << " to sign this form\nColleagues: 'Go back to cleaning toilets, " << bureaucrat.getName() << "!' * lololol *\n";
}
