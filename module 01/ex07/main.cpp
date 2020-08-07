/*
Make a program called "replace" that takes a filename and two strings, let’s call them s1 and s2, that are NOT empty. 
It will open the file, and write its contents to FILENAME.replace, after replacinge very occurence of s1 with s2.
Of course, you will handle errors as best you can, and not use the C file manipulation functions? You will turn in some test files to show your program works.
*/

/*
take a file and make a new file, [filename].replace, in which every occurrence of s1 is replaces with s2
*/

#include <iostream>
#include <fstream>

int main()
{
	std::fstream testFile ("testfile.txt");
	std::fstream testFile3("testfile3.txt");
	std::string toFind = "needles";
	std::size_t locationFound;
	std::string lineBuffer;

	if (testFile.is_open() && testFile3.is_open())
	{
		while (std::getline(testFile, lineBuffer))
		{
			while (1)
			{
				locationFound = lineBuffer.find(toFind);
				if (locationFound == std::string::npos)
					break;
				lineBuffer.replace(locationFound, toFind.length(),"preposition");
			}
			testFile3 << lineBuffer << std::endl;
		}
	}
	else
		std::cout << "error: file failed to open\n";
	testFile.close();
	return (0);
}

// Optimization: - Remember until where in lineBuffer we have looked for s1, so that it doesn't start looking at the beginning every time. - Store s1's length in a variable, so we don't have to run s1.length() every time .replace is used.