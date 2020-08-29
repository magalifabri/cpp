#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack(void)
	{
		std::cout << "default constructor called\n";
	}

	// "stacks (...) use an encapsulated object of a specific container class as its underlying container, providing a specific set of member functions to access its elements." "container_type" contains the type of this underlying container, and we can use the iterator type in its namespace.
	typedef typename std::stack<T>::container_type::iterator iterator;

	// c is the instance of the underlying container that stack is based on, which contains the begin() and end() interators
	iterator begin(void)
	{
		return (std::stack<T>::c.begin());
	}

	iterator end(void)
	{
		return (std::stack<T>::c.end());
	}
};

#endif