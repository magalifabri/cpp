#include <iostream>
#include <string>

int main(int ac, char **av)
{
	int i;
	int j;
	char character;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			character = av[i][j];
			if (character >= 'a' && character <= 'z')
				character = av[i][j] - 32;
			std::cout << character;
		}
	}
	std::cout << '\n';
	return (0);
}