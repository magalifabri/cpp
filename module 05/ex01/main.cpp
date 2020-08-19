#include "Bureaucrat.hpp"

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

std::ostream &operator<<(std::ostream &os, Form &form)
{
	os << "form's name: " << form.getName() << "\n"
	<< "form's signed status: " << form.getSignedStatus() << "\n"
	<< "grade needed to sign the form: " << form.getGradeNeededToSign() << "\n"
	<< "grade needed to execute the form: " << form.getGradeNeededToExecute();
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
	
	std::cout << YELLOW "\n testing Form creation\n" RESET;
	Form testForm("Test Form 1.7B", 2, 1);
	std::cout << "testForm.getName(): " << testForm.getName() << "\n";
	std::cout << "testForm.getSignedStatus(): " << testForm.getSignedStatus() << "\n";
	std::cout << "testForm.getGradeNeededToSign(): " << testForm.getGradeNeededToSign() << "\n";
	std::cout << "testForm.getGradeNeededToExecute(): " << testForm.getGradeNeededToExecute() << "\n";

	std::cout << YELLOW "\n testing signForm()\n" RESET;
	bill.signForm(testForm);
	ted.signForm(testForm);
	ted.signForm(testForm);

	std::cout << YELLOW "\n testing << form\n" RESET;
	std::cout << testForm << "\n";

	std::cout << YELLOW "\n testing done()\n" RESET;
	return (0);
}

/*
clang++ -Wall -Wextra -Werror main.cpp Bureaucrat.cpp Form.cpp && ./a.out 
*/