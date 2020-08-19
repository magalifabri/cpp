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

// class Bureaucrat
// {
// private:
// 	std::string name;
// 	int grade;

// public:
// 	Bureaucrat(std::string const &name, int const &grade);
// 	class myexception : public std::exception
// 	{
// 		virtual const char *what() const throw()
// 		{
// 			return ("exception thrown: grade too high or too low");
// 		}
// 	};
// 	myexception myex;
// 	~Bureaucrat(void);
// 	std::string getName(void) const;
// 	int getGrade(void) const;
// 	void incrementGrade(void);
// 	void decrementGrade(void);
// 	void GradeTooHighException(void);
// 	void GradeTooLowException(void);
// };
// Bureaucrat::Bureaucrat(std::string const &nameParam, int const &gradeParam)
// {
// 	std::cout << "constructor: Bureaucrat: " << nameParam << ", " << gradeParam << "\n";
// 	name = nameParam;
// 	grade = gradeParam;
// }
// Bureaucrat::~Bureaucrat(void)
// {
// 	std::cout << "destructor: Bureaucrat: " << name << "\n";
// }
// std::string Bureaucrat::getName(void) const
// {
// 	return (name);
// }
// int Bureaucrat::getGrade(void) const
// {
// 	return (grade);
// }
// void Bureaucrat::incrementGrade(void)
// {
// 	std::cout << "incrementGrade() called\n -> grade increased from " << grade << " to " << grade - 1 << "\n";
// 	grade -= 1;
// 	try
// 	{
// 		if (grade < 1)
// 			throw myex;
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 		GradeTooHighException();
// 	}
// }
// void Bureaucrat::decrementGrade(void)
// {
// 	std::cout << "decrementGrade() called\n -> grade decreased from " << grade << " to " << grade + 1 << "\n";
// 	grade += 1;
// 	try
// 	{
// 		if (grade > 150)
// 			throw;
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 		GradeTooLowException();
// 	}
// }
// void Bureaucrat::GradeTooHighException(void)
// {
// 	std::cout << "GradeTooHighException() called:\n -> grade changed from " << grade << " to 75\n";
// 	grade = 75;
// }
// void Bureaucrat::GradeTooLowException(void)
// {
// 	std::cout << "GradeTooLowException() called:\n -> grade changed from " << grade << " to 75\n";
// 	grade = 75;
// }

std::ostream &operator<<(std::ostream &os, Bureaucrat const &x)
{
	os << x.getName() << ", bureaucrat grade " << x.getGrade();
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
	return (0);
}