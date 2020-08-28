#include "span.hpp"

span::span(unsigned int nParam)
{
	std::cout << "custom constructor called\n";

	n = nParam;
	ints = new int[n];
	nAdded = 0;
}

void span::addNumber(int numberParam)
{

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
	if (index < 0 || index >= (int)n)
		throw std::exception();
	return (ints[index]);
}

int span::size(void)
{
	return (n);
}