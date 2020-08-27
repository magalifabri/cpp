#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define REVERSED "\033[7m"

template <class T>
class Array
{
	T *array;
	unsigned int arraySize;

public:
	Array()
	{
		std::cout << CYAN "default constructor called\n" RESET;

		array = nullptr;
		arraySize = 0;
	}

	Array(unsigned int n)
	{
		std::cout << CYAN "constructor called\n" RESET;

		array = new T[n];
		arraySize = n;
	}

	Array(Array const &arrayParam)
	{
		std::cout << CYAN "copy constructor called\n" RESET;
		
		array = nullptr;
		arraySize = 0;
		operator=(arrayParam);
	}

	// this array, to which we want to assign an other array, needs to have the same array size as the other. So if it doesn't, we first delete it to create a new array with the correct size
	void operator=(Array const &arrayParam)
	{
		std::cout << CYAN "assignment operator called\n" RESET;

		unsigned int i;

		if (arraySize != arrayParam.size())
		{
			if (array != nullptr)
				delete [] array;
			array = new T[arrayParam.size()];
			arraySize = arrayParam.size();
		}
		i = -1;
		while (++i < arraySize)
			array[i] = arrayParam[i];
	}

	T &operator[](size_t index) const
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

	~Array(void)
	{
		std::cout << MAGENTA "destructor called\n" RESET;
	}
};

#endif
