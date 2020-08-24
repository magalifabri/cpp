#include "Serialization.hpp"

void *serialize(void)
{
	std::string alnum;
	char *alnumArray;
	int i;

	srand(time(NULL));
	alnumArray = new char[18];
	alnum = "0123456789abcdefghijklmnopqrstuvwxyz";
	i = -1;
	while (++i < 8)
		alnumArray[i] = alnum[rand() % 36];
	alnumArray[i] = alnum[rand() % 9];
	while (++i < 17)
		alnumArray[i] = alnum[rand() % 36];
	alnumArray[++i] = '\0';
	return (alnumArray);
}

Data *deserialize(void *raw)
{
	Data *data;
	char *rawChar;
	std::string rawString;

	data = new Data;
	rawChar = (char*)raw;
	rawString = rawChar;

	data->s1 = rawString.substr(0, 8);
	data->n = (int)(rawChar[8] - '0');
	data->s2 = rawString.substr(9, 8);
	return (data);
}

int main()
{
	void *raw;
	Data *data;

	std::cout << "calling serialize()...\n";
	raw = serialize();
	std::cout << "serialize() returned void ptr: " << raw << "\n"; // TEST
	std::cout << "stored at this memory location: " << (char*)raw << "\n";

	std::cout << "calling deserialize()...\n";
	data = deserialize(raw);
	std::cout << "deserialize() returned instance of Data struct with following values:\n";
	std::cout << "data->s1:\t" << data->s1 << "\n";
	std::cout << "data->n:\t" << data->n << "\n";
	std::cout << "data->s2:\t" << data->s2 << "\n";
	return (0);
}
