#include "mutantstack.hpp"
// #include <iostream>
// #include <stack>
// #include <list>

// template <typename T>
// class MutantStack : public std::stack<T>
// {
// public:
// 	MutantStack(void)
// 	{
// 		std::cout << "default constructor called\n";
// 	}

// 	// "stacks (...) use an encapsulated object of a specific container class as its underlying container, providing a specific set of member functions to access its elements." "container_type" contains the type of this underlying container, and we can use the iterator type in its namespace.
// 	typedef typename std::stack<T>::container_type::iterator iterator;

// 	// c is the instance of the underlying container that stack is based on, which contains the begin() and end() interators
// 	iterator begin(void)
// 	{
// 		return (std::stack<T>::c.begin());
// 	}

// 	iterator end(void)
// 	{
// 		return (std::stack<T>::c.end());
// 	}
// };

int main()
{
	{
		std::cout << "creating instance of MutantStack, ms...\n";
		MutantStack<int> ms;
		std::cout << "ms.size(): " << ms.size() << "\n";
		std::cout << "ms.empty(): " << ms.empty() << "\n";
		std::cout << "push()ing 3, 6, 9 and 11 to ms...\n";
		ms.push(3);
		ms.push(6);
		ms.push(9);
		ms.push(11);
		std::cout << "ms.size(): " << ms.size() << "\n";
		std::cout << "ms.empty(): " << ms.empty() << "\n";
		std::cout << "ms.top(): " << ms.top() << "\n";
		std::cout << "pop()ping once...\n";
		ms.pop();
		std::cout << "ms.size(): " << ms.size() << "\n";
		std::cout << "ms.top(): " << ms.top() << "\n";
		std::cout << "creating iterators...\n";
		MutantStack<int>::iterator it = ms.begin();
		MutantStack<int>::iterator ite = ms.end();
		std::cout << "using iterators, printing all values in ms...\n";
		while (it != ite)
			std::cout << *it++ << "\n";
		std::cout << "copying ms to std::stack s...\n";
		std::stack<int> s(ms);
		std::cout << "s.size(): " << s.size() << "\n";
		std::cout << "s.top(): " << s.top() << "\n";
	}
	{
		std::cout << "creating instance of std::list, myList...\n";
		std::list<int> myList;
		std::cout << "myList.size(): " << myList.size() << "\n";
		std::cout << "myList.empty(): " << myList.empty() << "\n";
		std::cout << "push_back()ing 3, 6, 9 and 11 to myList...\n";
		myList.push_back(3);
		myList.push_back(6);
		myList.push_back(9);
		myList.push_back(11);
		std::cout << "myList.size(): " << myList.size() << "\n";
		std::cout << "myList.empty(): " << myList.empty() << "\n";
		std::cout << "myList.back(): " << myList.back() << "\n";
		std::cout << "pop_back()ping once...\n";
		myList.pop_back();
		std::cout << "myList.size(): " << myList.size() << "\n";
		std::cout << "myList.back(): " << myList.back() << "\n";
		std::cout << "creating iterators...\n";
		std::list<int>::iterator it = myList.begin();
		std::list<int>::iterator ite = myList.end();
		std::cout << "using iterators, printing all values in myList...\n";
		while (it != ite)
			std::cout << *it++ << "\n";
	}
	return (0);
}