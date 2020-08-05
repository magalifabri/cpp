#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/time.h>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

/*
<iostream> : cout, cin
<string> : string
<unistd.h> : sleep
<sys/time.h> : gettimeofday
"Zombie.hpp"
"ZombieEvent.hpp"
*/

#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define REVERSED "\033[7m"

std::string get_growl(void);
std::string createRandomName(void);
long long get_current_time(void);

#endif