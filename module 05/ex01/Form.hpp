#ifndef FORM_HPP
#define FORM_HPP

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

#include "Bureaucrat.hpp"

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
private:
	std::string name;
	int signedStatus;
	int gradeNeededToSign;
	int gradeNeededToExecute;

public:
	Form(std::string const &name, int const &gradeNeededToSign, int const &gradeNeededToExecute);
	~Form(void);
	std::string getName(void) {return name;}
	int getSignedStatus(void) {return signedStatus;}
	int getGradeNeededToSign(void) {return gradeNeededToSign;}
	int getGradeNeededToExecute(void) {return gradeNeededToExecute;}
	void beSigned(Bureaucrat const &bureaucrat);
	void GradeTooHighException(Bureaucrat const &bureaucrat);
	void GradeTooLowException(Bureaucrat const &bureaucrat);
	class formception : public std::exception
	{
		virtual const char *what() const throw()
		{
			return (RED "exception thrown: grade too low" RESET);
		}
	};
	formception tooLow;
};

#endif