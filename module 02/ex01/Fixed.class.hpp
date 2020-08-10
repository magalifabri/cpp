#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP

#include <string>
#include <iostream>
#include <math.h>

class Fixed
{
private:
	int fixedPointValue;
	static const int fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &);
	Fixed(const int);
	Fixed(const float);
	void operator=(const Fixed &);
	~Fixed();
	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &os, const Fixed &x);

#endif