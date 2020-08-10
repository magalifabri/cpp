#include "Fixed.class.hpp"

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
