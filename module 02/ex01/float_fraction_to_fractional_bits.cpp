#include <math.h>

int getFraction(float fraction, int fractionalBits)
{
	int power = 0;
	char *str;
	str = new char[9];
	while (++power <= 8)
	{
		if (fraction > 1 / pow(2, power))
		{
			str[power - 1] = '1';
			fraction -= 1 / pow(2, power);
		}
		else
			str[power - 1] = '0';
	}
	str[power - 1] = '\0';

	int intFraction = 0;
	int i = -1;
	while (str[++i])
	{
		if (str[i] == '1')
			intFraction += (1 / pow(2, i + 1)) * pow(10, fractionalBits);
	}
	return 0;
}