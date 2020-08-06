#include "main.hpp"


// -------------------------- BRAIN CLASS -------------------------------------


// class Brain
// {
// public:
// 	Brain();
// 	~Brain();
// 	std::string identify() const;
// };

// Brain::Brain(void)
// {
// 	std::cout << BLUE "Brain constructed\n" RESET;
// }

// Brain::~Brain(void)
// {
// 	std::cout << BLUE "Brain destructed\n" RESET;
// }

// std::string Brain::identify(void) const
// {
// 	const Brain *address;
// 	std::string str_address;
//     std::ostringstream get_the_address; 

// 	address = this;
// 	std::cout << "address: " << address << std::endl;
//     get_the_address << address;
//     str_address = get_the_address.str(); 
// 	std::cout << "str_address: " << str_address << std::endl;
// 	return (str_address);
// }


// -------------------------- HUMAN CLASS -------------------------------------


// class Human
// {
// public:
// 	const Brain humanBrain;
// 	std::string identify();
// };

// std::string Human::identify(void)
// {
// 	return (humanBrain.identify());
// }


// -------------------------- MAIN --------------------------------------------


// For const objects you may call only member functions that have qualifier const. https://stackoverflow.com/questions/20252932/the-object-has-type-qualifiers-that-are-not-compatible-with-the-member-function
int main()
{
	Human bob;
	std::cout << bob.identify() << std::endl;
	std::cout << bob.humanBrain.identify() << std::endl;
	return (0);
}
