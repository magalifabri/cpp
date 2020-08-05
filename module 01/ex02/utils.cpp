#include "main.hpp"

std::string get_growl(void)
{
	std::string growl[4];
	
	growl[0] = "bwwrrraaaahhh";
	growl[1] = "grrruuaaahh";
	growl[2] = "raaawwwhhh";
	growl[3] = "bhuuuaaaahhh";
	return (growl[rand() % 3]);
}

std::string createRandomName(void)
{
	std::string vowels;
	std::string consonants;
	char name[4];

	srand(time(NULL));
	vowels = "aeuioy";
	consonants = "qwrtpsdfghjklzxcvbnm";
	name[0] = consonants[rand() % 20];
	name[1] = vowels[rand() % 6];
	name[2] = consonants[rand() % 20];
	name[3] = '\0';
	return (name);
}

long long get_current_time(void)
{
	struct timeval tp;
	long long time;

	if (gettimeofday(&tp, 0) == -1)
		return (-1);
	time = tp.tv_sec;
	time *= 1000;
	time += (tp.tv_usec / 1000);
	return (time);
}
