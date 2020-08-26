#include <iostream>
#include <string>

template <class T>
void print(T x)
{
	std::cout << x << "\n";
}

template <class T, typename F>
void iter (T array[], int arrayLen, F function)
{
	int i;

	i = -1;
	while (++i < arrayLen)
		function(array[i]);
}

int main()
{
	int intArray[] = {1, 2, 3};
	iter(intArray, 3, print<int>);

	std::string stringArray[] = {"one", "two", "three"};
	iter(stringArray, 3, print<std::string>);
}
