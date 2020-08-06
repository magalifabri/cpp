#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Brain.hpp"
#include <string>

class Human
{
public:
	const Brain humanBrain;
	std::string identify();
};

#endif