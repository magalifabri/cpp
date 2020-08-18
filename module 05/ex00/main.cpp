#include "Bureaucrat.hpp"

#include <string>
#include <iostream>
#include <exception>


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
	Bureaucrat ted("Teddy", 2);
	std::cout << ted << "\n";
	ted.incrementGrade();
	ted.incrementGrade();
	std::cout << ted << "\n";
	return (0);
}