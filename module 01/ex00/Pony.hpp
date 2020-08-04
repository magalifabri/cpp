#ifndef PONY_HPP
#define PONY_HPP

#include <iostream>
#include <string>

class Pony
{
public:
	Pony(void);
	~Pony(void);
	std::string name;
	std::string hairColor;
	std::string weight;
	std::string height;
	void eat(void);
	void shit(void);
	void sleep(void);
};

#endif