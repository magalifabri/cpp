#include "Fixed.class.hpp"
#include <string>
#include <iostream>

int main()
{
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;
	std::cout << a.getRawBits() << "\n";
	std::cout << b.getRawBits() << "\n";
	std::cout << c.getRawBits() << "\n";
}


/*
-------------------------- FIXED CLASS -------------------------------------

class Fixed
{
	private:
	int fixedPointValue;
	static const int fractionalBits;
	
	public:
	Fixed();
	Fixed(const Fixed &);
	void operator= (const Fixed &);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
	fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &x)
{
	std::cout << "Copy constructor called\n";
	operator=(x);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

void Fixed::operator= (const Fixed &x)
{
	std::cout << "Assignation operator called\n";
	fixedPointValue = x.getRawBits();
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called \n";
	return (fixedPointValue);
}
*/