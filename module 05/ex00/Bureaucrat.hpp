#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

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
			return ("exception thrown: grade too high or too low");
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
};

#endif