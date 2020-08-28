#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

#define RED "\033[0;31m"
#define RESET "\033[0m"

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

#endif