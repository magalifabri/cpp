#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
public:
	Zombie(void);
	~Zombie(void);
	std::string type;
	std::string name;
	void announce(void);
};

std::string get_growl(void);

#endif