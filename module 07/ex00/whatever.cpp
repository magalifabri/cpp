#include <iostream>
#include <string>

template <class T>
void swap (T &x, T &y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

template <class T>
T min (T &x, T &y)
{
	if (x < y)
		return (x);
	return (y);
}

template <class T>
T max (T &x, T &y)
{
	if (x > y)
		return (x);
	return (y);
}

int main()
{
	std::cout << "test with ints\n";
	int a = 2;
	int b = 3;

	std::cout << "a == " << a << ", b == " << b << "\n";
	std::cout << "calling swap()..\n";
	::swap(a, b);
	std::cout << "a == " << a << ", b == " << b << "\n";
	std::cout << "calling min(a, b)..\n";
	std::cout << "min(a, b) returns " << min(a, b) << "\n";
	std::cout << "calling max(a, b)..\n";
	std::cout << "max(a, b) returns " << max(a, b) << "\n";
	

	std::cout << "\ntest with std::strings\n";
	std::string c = "test1";
	std::string d = "test2";

	std::cout << "c == '" << c << "', d == '" << d << "'\n";
	std::cout << "calling swap()..\n";
	::swap(c, d);
	std::cout << "c == '" << c << "', d == '" << d << "'\n";
	std::cout << "calling min(c, d)..\n";
	std::cout << "min(c, d) returns '" << min(c, d) << "'\n";
	std::cout << "calling max(c, d)..\n";
	std::cout << "max(c, d) returns '" << max(c, d) << "'\n";
}