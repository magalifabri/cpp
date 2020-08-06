#include <string>
#include <iostream>

int main()
{
	std::string str;
	std::string *ptr;
	std::string ref;

	str = "HI THIS IS BRAIN";
	std::cout << "str: " << str << std::endl;
	std::cout << "&(address of)str: " << &str << std::endl;
	ptr = &str;
	std::cout << "ptr = &str\n";
	std::cout << "ptr: " << ptr << std::endl;
	std::cout << "*(value pointed to by)ptr: " << *ptr << std::endl;
	ref = *ptr;
	std::cout << "ref = *ptr\n";
	std::cout << "ref: " << ref << std::endl;
}
