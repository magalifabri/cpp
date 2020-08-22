#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#include <string>
#include <iostream>
#include <exception>

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

std::ostream &operator<<(std::ostream &os, Bureaucrat const &x)
{
	os << x.getName() << ", bureaucrat grade " << x.getGrade();
	return (os);
}

std::ostream &operator<<(std::ostream &os, Form *form)
{
	os << "form's name: " << form->getName() << "\n"
	<< "form's signed status: " << form->getSignedStatus() << "\n"
	<< "grade needed to sign the form: " << form->getGradeNeededToSign() << "\n"
	<< "grade needed to execute the form: " << form->getGradeNeededToExecute();
	return (os);
}

int main()
{
	std::cout << YELLOW "\n testing Bureaucrat creation, incrementGrade() + GradeTooHighException()\n" RESET;
	Bureaucrat ted("Teddy", 2);
	std::cout << ted << "\n";
	ted.incrementGrade();
	ted.incrementGrade();
	std::cout << ted << "\n";

	std::cout << YELLOW "\n testing decrementGrade() + GradeTooLowException\n" RESET;
	Bureaucrat bill("Billy", 150);
	std::cout << bill << "\n";
	bill.decrementGrade();
	std::cout << bill << "\n";
	
	std::cout << YELLOW "\n testing RobotomyRequestForm\n" RESET;
	srand(time(NULL));
	Form *RRF;
	RRF = new RobotomyRequestForm("your grandma");
	std::cout << "RRF->getName(): " << RRF->getName() << "\n";
	std::cout << "RRF->getSignedStatus(): " << RRF->getSignedStatus() << "\n";
	std::cout << "RRF->getGradeNeededToSign(): " << RRF->getGradeNeededToSign() << "\n";
	std::cout << "RRF->getGradeNeededToExecute(): " << RRF->getGradeNeededToExecute() << "\n";

	std::cout << YELLOW "\n testing signForm()\n" RESET;
	bill.signForm(RRF);
	ted.signForm(RRF);
	ted.signForm(RRF);

	std::cout << YELLOW "\n testing execute()\n" RESET;
	bill.executeForm(*RRF);
	ted.executeForm(*RRF);

	std::cout << YELLOW "\n testing << form\n" RESET;
	std::cout << RRF << "\n";
	
	std::cout << YELLOW "\n testing ShrubberyCreationForm\n" RESET;
	Form *SCF;
	SCF = new ShrubberyCreationForm("your backyard");
	ted.executeForm(*SCF);
	ted.signForm(SCF);
	ted.executeForm(*SCF);

	std::cout << YELLOW "\n testing PresidentialPardonForm\n" RESET;
	Form *PPF;
	PPF = new PresidentialPardonForm("President Trump");
	ted.signForm(PPF);
	ted.executeForm(*PPF);
	
	std::cout << YELLOW "\n testing Intern\n" RESET;
	Intern intern;
	Form *newForm;
	newForm = intern.makeForm("presidential thingy", "Again, President Trump");
	newForm = intern.makeForm("", "Again, President Trump");
	ted.signForm(newForm);
	ted.executeForm(*newForm);
	newForm = intern.makeForm("presidential pardon", "Again, President Trump");
	ted.signForm(newForm);
	ted.executeForm(*newForm);

	std::cout << YELLOW "\n testing done; delete'ing\n" RESET;
	delete RRF;
	delete SCF;
	delete PPF;
	delete newForm;
	return (0);
}

/*
clang++ -Wall -Wextra -Werror main.cpp Bureaucrat.cpp Form.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp Intern.cpp && ./a.out
*/