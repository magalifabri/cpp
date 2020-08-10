#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP

#include <iostream>

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

#endif