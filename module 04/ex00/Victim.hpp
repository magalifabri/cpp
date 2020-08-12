#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <iostream>
#include <string>

class Victim
{
	public:
	Victim(std::string name);
	~Victim(void);
	std::string name;
	void getPolymorphed() const;
};

#endif