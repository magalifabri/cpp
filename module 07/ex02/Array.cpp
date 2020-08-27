#include <iostream>
#include <string>

template <class T>
class Array
{
	T *array;
	unsigned int arraySize;

public:
	Array()
	{
		std::cout << "default constructor called\n";

		array = nullptr;
		arraySize = 0;
	}

	Array(unsigned int n)
	{
		std::cout << "constructor called\n";

		array = new T[n];
		arraySize = n;
	}

	Array(Array const arrayParam[])
	{
		std::cout << "copy constructor called\n";

		operator=(arrayParam);
	}

	// this array, to which we want to assign an other array, needs to have the same array size as the other. So if it doesn't, we first delete it to create a new array with the correct size
	void operator=(Array const arrayParam[])
	{
		std::cout << "assignment operator called\n";

		int i;

		if (arrayParam->arraySize() != arraySize)
		{
			delete [] array;
			array = new T[arrayParam->arraySize()];
			arraySize = arrayParam->arraySize();
		}
		i = -1;
		while (++i < arraySize)
			array[i] = arrayParam[i];
	}

	T &operator[](size_t index)
	{
		if (array == nullptr
		|| index > arraySize
		|| index < 0)
			throw std::exception();
		return (array[index]);
	}

	unsigned int size(void) const
	{
		return (arraySize);
	}
};

int main()
{
	std::cout << "initialize arr1 without args...\n";
	Array <int>arr1;
	std::cout << "initialize arr2(5)...\n";
	Array <int>arr2(5);
	unsigned int i;

	std::cout << "writing values to arr2...\n";
	i = -1;
	while (++i < arr2.size())
		arr2[i] = i + 100;
	
	std::cout << "reading values from arr2...\n";
	i = -1;
	while (++i < arr2.size())
		std::cout << "arr2[" << i << "]: " << arr2[i] << "\n";
	
	std::cout << "copying arr2 to arr1...\n";
	arr1 = arr2;
	i = -1;
	while (++i < arr1.size())
		std::cout << "arr1[" << i << "]: " << arr1[i] << "\n";
}