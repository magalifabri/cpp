#include <iostream>
#include <string>

template <typename T>
int easyfind(T &container, int toFind)
{
	// int index;

	typename T::iterator index = std::find(container.begin(), container.end(), toFind);
	if (index == container.end())
	{
		std::cout << toFind << " not found\n";
		throw std::exception();
	}
	else
	{
		std::cout << toFind << " found at index " << index << "\n";
	}
	return (index);
}

int main()
{
	int array[] = {1, 2, 3};
	easyfind(array, 2);
}