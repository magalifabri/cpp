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

/*
** Takes a constant integer as a parameter and converts it to the correspondant
** fixed(8) point value
*/
Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called\n";
	fixedPointValue = n * pow(2, fractionalBits);
}

/*
** Takes a constant floating point as a parameter and that converts it to the
** correspondant fixed(8) point value.
*/
Fixed::Fixed(const float n)
{

	std::cout << "Float constructor called\n";
	fixedPointValue = n * pow(2, fractionalBits);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

void Fixed::operator=(const Fixed &x)
{
	std::cout << "Assignation operator called\n";
	fixedPointValue = x.getRawBits();
}

int Fixed::getRawBits(void) const
{
	return (fixedPointValue);
}

/*
Converts the fixed point value to a floating point value
*/
float Fixed::toFloat(void) const
{
	return (fixedPointValue / pow(2, fractionalBits));
}

/*
Converts the fixed point value to an integer value
*/
int Fixed::toInt(void) const
{
	return (fixedPointValue >> 8);
}

/*
** Output stream operator overload
** 
** Inserts a floating point representation of the fixed point value into the
** parameter output stream.
** 
** Function Summary:
** - if the fractional bits (lowest 8) are all 0, we're (as good as) dealing
**   with an integer (because the number doesn't have a fractional part), so we
**   can just bitshift >> 8 to undo the integer to fixed point value conversion
**   and write.
** - if that is not the case, we use "x.getRawBits() / pow(2, 8)" to undo the
**   conversion to fixed point value, as this results in a floating point
**   number, because pow returns a double.
*/
std::ostream &operator<<(std::ostream &os, const Fixed &x)
{
	if ((x.getRawBits() & 255) == 0)
		os << (x.getRawBits() >> 8);
	else
		os << x.getRawBits() / pow(2, 8);
	return (os);
}
