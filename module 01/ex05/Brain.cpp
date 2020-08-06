#include "Brain.hpp"

Brain::Brain(void)
{
	// std::cout << "Brain constructed\n";
}

Brain::~Brain(void)
{
	// std::cout << "Brain destructed\n";
}

std::string Brain::identify(void) const
{
	const Brain *address;
	std::string str_address;
    std::ostringstream get_the_address; 

	address = this;
	// std::cout << "address: " << address << std::endl;
    get_the_address << address;
    str_address = get_the_address.str(); 
	// std::cout << "str_address: " << str_address << std::endl;
	return (str_address);
}