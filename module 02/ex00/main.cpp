#include <string>
#include <iostream>

class Fixed
{
	private:
	int fixedPointValue; // An integer to store the fixed point value.
	static const int fractionalBits; // A static constant integer to store the number of fractional bits. This constant will always be the literal 8.
	
	public:
	Fixed(); // default constructor that initializes the fixed point value to 0.
	Fixed(const Fixed &); // copy constructor.
	void operator= (const Fixed &); // An assignation operator overload.
	~Fixed(); // destructor
	int getRawBits(void) const; // returns the raw value of the fixed point value.
	void setRawBits(int const raw); // sets the raw value of the fixed point value.
};

// default constructor
Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
	fixedPointValue = 0;
}

// copy constructor
Fixed::Fixed(const Fixed &x)
{
	std::cout << "Copy constructor called\n";
	operator=(x);
}

// destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

// assignment operator overload
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