#include "span.hpp"

int main()
{
	{
		// create instance of span class
		span mySpan(3);

		// check existence of span class, its size and functioning of (non-mandatory) size() function
		std::cout << "mySpan.size(): " << mySpan.size() << "\n";

		// use addNumber() to add numbers to the container and check that it works correctly
		try
		{
			mySpan.addNumber(5);
			mySpan.addNumber(3);
			mySpan.addNumber(9);
			mySpan.addNumber(11);
		}
		catch(const std::exception& e)
		{
			std::cout << RED "container full\n" RESET;
		}
		
		// verify that the container now holds the added integers with (non-mandatory) operator[]
		try
		{
			std::cout << "value of int stored at mySpan[0]: " << mySpan[0] << "\n";
			std::cout << "value of int stored at mySpan[1]: " << mySpan[1] << "\n";
			std::cout << "value of int stored at mySpan[2]: " << mySpan[2] << "\n";
			std::cout << "value of int stored at mySpan[3]: " << mySpan[3] << "\n";
		}
		catch(const std::exception& e)
		{
			std::cout << RED "invalid index\n" RESET;
		}

		// test longestSpan()
		std::cout << "mySpan.longestSpan(): " << mySpan.longestSpan() << "\n";

		// test shortestSpan()
		int shortest = mySpan.shortestSpan();
		std::cout << "mySpan.shortestSpan(): " << shortest << "\n";
	}
	{
		span mySpan2(10000);
		int i;
		
		srand(time(NULL));
		
		std::cout << "adding numbers...\n";	
		i = -1;
		while (++i < mySpan2.size())
			mySpan2.addNumber(rand() % 2147483647);

		std::cout << "mySpan2.longestSpan(): " << mySpan2.longestSpan() << "\n";
		std::cout << "mySpan2.shortestSpan(): " << mySpan2.shortestSpan() << "\n";
	}
	return (0);
}