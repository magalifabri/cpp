#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

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

#include "Form.hpp"

#include <string>
#include <iostream>
#include <exception>

class Form;

class Bureaucrat
{
private:
	std::string name;
	int grade;

public:
	Bureaucrat(std::string const &name, int const &grade);
	class myexception : public std::exception
	{
		virtual const char *what() const throw()
		{
			return (RED "exception thrown: grade too high or too low" RESET);
		}
	};
	myexception myex;
	~Bureaucrat(void);
	std::string getName(void) const;
	int getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);
	void GradeTooHighException(void);
	void GradeTooLowException(void);
	void signForm(Form *form);
	void executeForm(Form const &form);
};

#endif