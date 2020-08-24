
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <climits>
#include <cfloat>
#include <math.h>

int main(int argc, char **argv)
{
	std::string s;
	int sLen;
	bool isInf;
	bool hasFrac;
	bool stringstreamFailed;
	long double d;
	int i;

	// check number of arguments
	if (argc <= 1)
	{
		std::cout << "error: too few arguments" << std::endl;
		return (0);
	}

	i = 0;
	while (++i < argc)
	{
		// convert argument char* to std::string
		s = argv[i];

		// get length of argument string
		sLen = s.length();

		// check argument string from nan/inf
		isInf = (s.compare(0, sLen, "nan") == 0
		|| s.compare(0, sLen, "-inf") == 0
		|| s.compare(0, sLen, "+inf") == 0
		|| s.compare(0, sLen, "nanf") == 0
		|| s.compare(0, sLen, "-inff") == 0
		|| s.compare(0, sLen, "+inff") == 0);

		// check if argument string has a fractional part
		hasFrac = s.find('.') != std::string::npos;
		
		// if we're not dealing with nan/inf and trailing f is present, remove f
		if (!isInf && s[sLen - 1] == 'f')
			s = s.substr(0, sLen - 1);
		
		// cast value to an int or convert to double
		stringstreamFailed = 0;
		if (sLen == 1 && std::isprint(s[0]))
			d = (int)(s[0]);
		else
		{
			std::istringstream ss(s);
			ss >> d;
			if (ss.fail())
			{
				std::cout << "Failed\n";
				stringstreamFailed = 1;
			}
			std::cout << d << "\n";
		}

		// output results
		std::cout << "input:\t\t" << argv[i] << "\n";

		// char
		if (isinf(d) || isnan(d) || d < CHAR_MIN || d > CHAR_MAX)
			std::cout << " - char:\timpossible\n";
		else if (std::isprint(d))
			std::cout << " - char:\t'" << (char)d << "'\n";
		else
			std::cout << " - char:\tNon displayable\n";

		// int
		if (stringstreamFailed || isinf(d) || isnan(d) || d < INT_MIN || d > INT_MAX)
			std::cout << " - int:\t\timpossible\n";
		else
			std::cout << " - int:\t\t" << (int)d << "\n";

		// float
		if (d < FLT_MIN || d > FLT_MAX)
			std::cout << " - float:\timpossible\n";
		else if (hasFrac == true)
			std::cout << " - float:\t" << (float)d << "f\n";
		else
			std::cout << " - float:\t" << std::setprecision(1) << std::fixed
			<< (float)d << "f\n";

		// double
		if (d < DBL_MIN || d > DBL_MAX)
			std::cout << " - double:\timpossible\n";
		else
			std::cout << " - double:\t" << (double)d << "\n";
		std::cout << std::endl;
	}
}