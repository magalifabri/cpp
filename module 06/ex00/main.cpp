#include <iostream>
#include <string>
#include <sstream>

int main(int ac, char **av)
{
	int integer;
	int i = 0;
	while (++i < ac)
	{
		std::cout << "given input:\t\t" << av[i] << "\n";
		std::stringstream str(av[i]);
		str >> integer;
		if (integer != 0) // av[i] is a number
			std::cout << "(1)input as integer:\t" << integer << "\n";
		else // av[i] is a letter
			std::cout << "(2)input as integer:\t" << (int)av[i][0] << "\n";
		
		std::istringstream str2(av[i]);
		float floater;
		str2 >> floater;
		if (floater != 0) // av[i] is a number
			std::cout << "(1)input as float:\t" << floater << "\n";
		else // av[i] is a letter
			std::cout << "(2)input as float:\t" << (float)av[i][0] << "\n";
		
		std::istringstream str3(av[i]);
		double doubler;
		str3 >> doubler;
		if (doubler != 0) // av[i] is a number
			std::cout << "(1)input as double:\t" << doubler << "\n";
		else // av[i] is a letter
			std::cout << "(2)input as double:\t" << (double)av[i][0] << "\n";

		// std::cout << "input as float:\t\t" << integer << "\n";
		// std::cout << "input as double:\t" << integer << "\n\n";
		std::cout << "\n";
	}

	// int integer;
	float f;
	double d;
	i = 0;
	while (++i < ac)
	{
		if ((av[i][0] >= 'a' && av[i][0] <= 'z')
		|| (av[i][0] >= 'A' && av[i][0] <= 'Z'))
		{
			integer = (int)(av[i][0]);
			std::cout << "input as integer:\t" << integer << "\n";
			f = (float)(av[i][0]);
			std::cout << "input as float:\t\t" << f << "f\n";
			d = (double)(av[i][0]);
			std::cout << "input as double:\t" << d << "\n";
		}
		else
		{
			std::string str = av[i];
			integer = std::stoi(str);
			std::cout << "input as integer:\t" << integer << "\n";
			f = std::stof(str);
			std::cout << "input as float:\t\t" << f << "f\n";
			d = std::stod(str);
			std::cout << "input as double:\t" << d << "\n";
		}
	}
	

	return (0);
}