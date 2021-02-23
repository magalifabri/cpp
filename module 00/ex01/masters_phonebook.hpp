#ifndef MASTERS_PHONEBOOK_HPP
# define MASTERS_PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>
# include <unistd.h>

# define MAX_CONTACTS 8

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"
# define BOLD "\033[1m"
# define UNDERLINE "\033[4m"
# define REVERSED "\033[7m"

/*
All the member data attributes are private, so they are less easily tampered
with. To set the value to the attributes and retrieve the value stored in
them, a public set_data_member & get_data_member function are provided. To
furter secure the data members in our struct, the get_data_member returns a
const, as it should not be modified.
*/

class contact_data
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string login;
	std::string postal_address;
	std::string email_address;
	std::string phone_number;
	std::string birthday_date;
	std::string favorite_meal;
	std::string underwear_color;
	std::string darkest_secret;
	std::string first_name_short;
	std::string last_name_short;
	std::string nickname_short;
public:
	void set_data_member(std::string member_name, std::string member_data);		
	std::string get_data_member(std::string member_name) const;
};

void welcome_message(void);

#endif
