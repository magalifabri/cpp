#include <iostream>
#include <fstream>

void replaceAndCopy(std::ifstream &srcFile, std::ofstream &replaceFile,
std::string &toFind, std::string &replaceWith)
{
	size_t toFindLength;
	std::string lineBuffer;
	std::size_t locationFound;

	toFindLength = toFind.length();
	if (srcFile.is_open() && replaceFile.is_open())
	{
		while (std::getline(srcFile, lineBuffer))
		{
			while (1)
			{
				locationFound = lineBuffer.find(toFind);
				if (locationFound == std::string::npos)
					break;
				lineBuffer.replace(locationFound, toFindLength, replaceWith);
			}
			replaceFile << lineBuffer << std::endl;
		}
	}
	else
		std::cout << "error: file failed to open\n";
}

int main(int ac, char **av)
{
	std::ifstream srcFile;
	std::ofstream replaceFile;
	std::string toFind;
	std::string replaceWith;

	if (ac != 4)
	{
		std::cout << "error: incorrect number of arguments\n";
		return (0);
	}
	srcFile.open(av[1]);
	replaceFile.open(av[1] + (std::string)".replace");
	toFind = av[2];
	replaceWith = av[3];
	replaceAndCopy(srcFile, replaceFile, toFind, replaceWith);
	srcFile.close();
	return (0);
}

/*
** Optimization: - Remember until where in lineBuffer we have looked for s1,
** so that it doesn't start looking at the beginning every time.
*/