#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <unistd.h>

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

class contact_data
{
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string first_name_short;
		std::string last_name_short;
		std::string nickname_short;
		std::string login;
		std::string postal_address;
		std::string email_address;
		std::string phone_number;
		std::string birthday_date;
		std::string favorite_meal;
		std::string underwear_color;
		std::string darkest_secret;
};

void welcome_message(void);