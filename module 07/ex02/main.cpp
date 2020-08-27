#include "Array.hpp"

int main()
{
	std::cout << YELLOW "initialize arr1 without args...\n" RESET;
	Array <int>arr1;
	std::cout << YELLOW "initialize arr2(5)...\n" RESET;
	Array <int>arr2(5);
	unsigned int i;

	std::cout << YELLOW "writing values to arr2...\n" RESET;
	i = -1;
	while (++i < arr2.size())
		arr2[i] = i + 100;
	
	std::cout << YELLOW "reading values from arr2...\n" RESET;
	i = -1;
	while (++i < arr2.size())
		std::cout << "arr2[" << i << "]: " << arr2[i] << "\n";
	
	std::cout << YELLOW "assigning arr2 to arr1...\n" RESET;
	arr1 = arr2;
	i = -1;
	while (++i < arr1.size())
		std::cout << "arr1[" << i << "]: " << arr1[i] << "\n";

	std::cout << YELLOW "initializing arr3 with arr1...\n" RESET;
	Array<int> arr3(arr1);

	std::cout << YELLOW "reading values from arr3...\n" RESET;
	i = -1;
	while (++i < arr3.size())
		std::cout << "arr3[" << i << "]: " << arr3[i] << "\n";
}
