#include <iostream>
#include <string>

class Base
{
public:
	virtual ~Base(void);
};

Base::~Base(void) {}

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base * generate(void)
{
	int randomNumber;
	Base *instance;

	srand(time(NULL));
	randomNumber = rand() % 3;
	if (randomNumber == 0)
	{
		instance = new A;
		std::cout << "class A generated\n";
	}
	else if (randomNumber == 1)
	{
		instance = new B;
		std::cout << "class B generated\n";
	}
	else
	{
		instance = new C;
		std::cout << "class C generated\n";
	}
	return (instance);
}

void identify_from_pointer(Base * p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "class A identified from pointer\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "class B identified from pointer\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "class C identified from pointer\n";
}

void identify_from_reference(Base & b)
{
	Base tmp;

	try
	{
		tmp = dynamic_cast<A &>(b);
		std::cout << "class A identified from reference\n";
	}
	catch(std::bad_cast exp) {}
	try
	{
		tmp = dynamic_cast<B &>(b);
		std::cout << "class B identified from reference\n";
	}
	catch(std::bad_cast exp) {}
	try
	{
		tmp = dynamic_cast<C &>(b);
		std::cout << "class C identified from reference\n";
	}
	catch(std::bad_cast exp) {}
}

int main()
{
	Base *instance;

	std::cout << "calling generate()...\n";
	instance = generate();
	std::cout << "calling identify_from_pointer()...\n";
	identify_from_pointer(instance);
	std::cout << "calling identify_from_reference...\n";
	identify_from_reference(*instance);
	return (0);
}
