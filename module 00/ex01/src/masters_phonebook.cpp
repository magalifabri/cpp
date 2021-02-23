#include "../masters_phonebook.hpp"

void contact_data::set_data_member(std::string member_name, std::string member_data)
{
	if (member_name.compare("first_name") == 0)
		first_name = member_data;
	else if (member_name.compare("last_name") == 0)
		last_name = member_data;
	else if (member_name.compare("nickname") == 0)
		nickname = member_data;
	else if (member_name.compare("login") == 0)
		login = member_data;
	else if (member_name.compare("postal_address") == 0)
		postal_address = member_data;
	else if (member_name.compare("email_address") == 0)
		email_address = member_data;
	else if (member_name.compare("phone_number") == 0)
		phone_number = member_data;
	else if (member_name.compare("birthday_date") == 0)
		birthday_date = member_data;
	else if (member_name.compare("favorite_meal") == 0)
		favorite_meal = member_data;
	else if (member_name.compare("underwear_color") == 0)
		underwear_color = member_data;
	else if (member_name.compare("darkest_secret") == 0)
		darkest_secret = member_data;
	else if (member_name.compare("first_name_short") == 0)
		first_name_short = member_data;
	else if (member_name.compare("last_name_short") == 0)
		last_name_short = member_data;
	else if (member_name.compare("nickname_short") == 0)
		nickname_short = member_data;
	else
		std::cout << "no member by that name found\n";
}

std::string contact_data::get_data_member(std::string member_name) const
{
	if (member_name.compare("first_name") == 0)
		return (first_name);
	else if (member_name.compare("last_name") == 0)
		return (last_name);
	else if (member_name.compare("nickname") == 0)
		return (nickname);
	else if (member_name.compare("login") == 0)
		return (login);
	else if (member_name.compare("postal_address") == 0)
		return (postal_address);
	else if (member_name.compare("email_address") == 0)
		return (email_address);
	else if (member_name.compare("phone_number") == 0)
		return (phone_number);
	else if (member_name.compare("birthday_date") == 0)
		return (birthday_date);
	else if (member_name.compare("favorite_meal") == 0)
		return (favorite_meal);
	else if (member_name.compare("underwear_color") == 0)
		return (underwear_color);
	else if (member_name.compare("darkest_secret") == 0)
		return (darkest_secret);
	else if (member_name.compare("first_name_short") == 0)
		return (first_name_short);
	else if (member_name.compare("last_name_short") == 0)
		return (last_name_short);
	else if (member_name.compare("nickname_short") == 0)
		return (nickname_short);
	else
		std::cout << "no member by that name found\n";
	return (NULL);
}
