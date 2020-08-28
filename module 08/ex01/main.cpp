#include <iostream>

// #define BLACK "\033[0;30m"
#define RED "\033[0;31m"
// #define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
// #define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"
// #define BOLD "\033[1m"
// #define UNDERLINE "\033[4m"
// #define REVERSED "\033[7m"

class span
{
	unsigned int n;
	int *ints;
	int nAdded;

public:
	span(unsigned int n);
	void addNumber(int number);
	int shortestSpan(void);
	int longestSpan(void);
	int& operator[](int index);
	int size(void);
};

span::span(unsigned int nParam)
{
	std::cout << "custom constructor called\n";

	n = nParam;
	ints = new int[n];
	nAdded = 0;
	// int i = -1;
	// while (ints[++i] < n)
	// 	ints[i] = nullptr;
}

void span::addNumber(int numberParam)
{
	// static int i;

	if (nAdded == (int)n)
		throw std::exception();
	ints[nAdded++] = numberParam;
	// std::cout << "added number " << ints[nAdded - 1] << " to ints index " << nAdded - 1 << "\n";
}

int span::shortestSpan(void)
{
	int i1;
	int i2;
	int difference;
	int shortestSpan;

	shortestSpan = ints[0] - ints[1];
	if (shortestSpan < 0)
		shortestSpan = -shortestSpan;
	i1 = 0;
	while (i1 < (int)n - 1)
	{
		i2 = i1 + 1;
		while (i2 < (int)n)
		{
			difference = ints[i1] - ints[i2];
			if (difference == 0)
				return (0);
			if (difference < 0)
				difference = -difference;
			// std::cout << "difference between ints[" << i1 << "] and ints[" << i2 << "] is " << difference << "\n";
			if (difference < shortestSpan)
				shortestSpan = difference;
			i2++;
		}
		i1++;
	}
	return (shortestSpan);
}

int span::longestSpan(void)
{
	int smallestNumber;
	int biggestNumber;
	int i;

	i = 0;
	smallestNumber = ints[i];
	biggestNumber = ints[i];
	while (++i < (int)n)
	{
		if (ints[i] < smallestNumber)
			smallestNumber = ints[i];
		if (ints[i] > biggestNumber)
			biggestNumber = ints[i];
	}
	return (biggestNumber - smallestNumber);
}

int& span::operator[](int index)
{
	// try
	// {
		if (index < 0 || index >= (int)n)
			throw std::exception();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cout << "invalid index\n";
	// 	// return (*);
	// }
	
	return (ints[index]);
}

int span::size(void)
{
	return (n);
}

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