#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &nameParam, int const &gradeParam)
{
	std::cout << CYAN "constructor: Bureaucrat: " << nameParam << ", " << gradeParam << "\n" RESET;
	name = nameParam;
	grade = gradeParam;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << MAGENTA "destructor: Bureaucrat: " << name << "\n" RESET;
}

std::string Bureaucrat::getName(void) const
{
	return (name);
}

int Bureaucrat::getGrade(void) const
{
	return (grade);
}

void Bureaucrat::incrementGrade(void)
{
	std::cout << "incrementGrade() called\n -> grade increased from " << grade << " to " << grade - 1 << "\n";
	grade -= 1;
	try
	{
		if (grade < 1)
			throw myex;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		GradeTooHighException();
	}
}

void Bureaucrat::decrementGrade(void)
{
	std::cout << "decrementGrade() called\n -> grade decreased from " << grade << " to " << grade + 1 << "\n";
	grade += 1;
	try
	{
		if (grade > 150)
			throw myex;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		GradeTooLowException();
	}
}

void Bureaucrat::GradeTooHighException(void)
{
	std::cout << "GradeTooHighException() called:\n -> grade changed from " << grade << " to " << grade + 1 << "\n";
	grade += 1;
}

void Bureaucrat::GradeTooLowException(void)
{
	std::cout << "GradeTooLowException() called:\n -> grade changed from " << grade << " to " << grade - 1 << "\n";
	grade -= 1;
}

void Bureaucrat::signForm(Form *form)
{
	std::cout << "Handing form '" << form->getName() << "' to " << name << " to sign it...\n";
	if (form->getSignedStatus() == 1)
		std::cout << name << ": 'That form is already signed, buttface!'\n";
	else
		form->beSigned(*this);
}

void Bureaucrat::executeForm(Form const & form)
{
	std::cout << "Handing form '" << form.getName() << "' to " << name << " to execute it...\n";
	form.execute(*this);
}
