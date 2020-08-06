#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <sstream>
#include <iostream> // TESTING

class Brain
{
public:
	Brain();
	~Brain();
	std::string identify() const;
};

#endif