#include "easyfind.hpp"

int main()
{
	// create a deque container
	std::deque<int> myDeq;

	// create an array to assign to deque
	int array[] = {3, 6, 9};

	// assign array values to deque
	myDeq.assign(array, array+3);

	// print deque size and content to show it works
	std::cout << "size: " << myDeq.size() << "\n";
	unsigned int i = -1;
	std::cout << "content:\n";
	while (++i < myDeq.size())
		std::cout << myDeq[i] << "\n";
	
	// test easyfind
	i = -1;
	while (++i < 10)
	{
		try
		{
			easyfind(myDeq, i);
		}
		catch(const std::exception& e)
		{
			std::cout << "value " << i << " not found\n";
		}
		
	}
}