#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <deque>

template <typename T>
int easyfind(T &container, int toFind)
{
	typename T::iterator index;

	index = std::find(container.begin(), container.end(), toFind);
	if (index == container.end())
		throw std::exception();
	else
		std::cout << "value " << toFind << " found at index " << index - container.begin() << "\n";
	return (*index);
}

#endif