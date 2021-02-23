#include "../masters_phonebook.hpp"

/*
** Note(s) on print_contact_list():
** 
** Parent function: search_cmd()
*/

int print_contact_list(contact_data contacts[], int &number_of_contacts)
{
	int j;

	std::cout << "You sought, and you found:\n\n"
	<< std::setw(10) << "Index" << "|"
	<< std::setw(10) << "First name" << "|"
	<< std::setw(10) << "Last name" << "|" 
	<< std::setw(10) << "Nickname" << "\n"
	<< "–––––––––––––––––––––––––––––––––––––––––––\n";
	j = -1;
	while (++j < number_of_contacts)
	{
		std::cout
		<< std::setw(10) << j << "|"
		<< std::setw(10) << contacts[j].get_data_member("first_name_short") << "|"
		<< std::setw(10) << contacts[j].get_data_member("last_name_short") << "|" 
		<< std::setw(10) << contacts[j].get_data_member("nickname_short") << "\n"
		<< "–––––––––––––––––––––––––––––––––––––––––––\n";
	}
	return (1);
}

/*
** Note(s) on process_index():
** 
** Parent function: search_cmd()
** 
** Function Summary:
** 1. check if requested index number is valid
** 2. display contact info
*/

int process_index(contact_data contacts[], int &number_of_contacts, int index)
{
	if (index < 0 || index > number_of_contacts - 1)
	{
		std::cout << RED BOLD "A number above -1 and below " 
		<< number_of_contacts << ", please.\n" RESET;
	}
	else
	{
		std::cout << "The contact information for index " << index << ": \n"
		<< " - first name: "<< contacts[index].get_data_member("first_name") << "\n"
		<< " - last name: "<< contacts[index].get_data_member("last_name") << "\n"
		<< " - nickname: "<< contacts[index].get_data_member("nickname") << "\n"
		<< " - login: "<< contacts[index].get_data_member("login") << "\n"
		<< " - postal address: "<< contacts[index].get_data_member("postal_address") << "\n"
		<< " - email address: "<< contacts[index].get_data_member("email_address") << "\n"
		<< " - phone number: "<< contacts[index].get_data_member("phone_number") << "\n"
		<< " - birthday date: "<< contacts[index].get_data_member("birthday_date") << "\n"
		<< " - favorite meal: "<< contacts[index].get_data_member("favorite_meal") << "\n"
		<< " - underwear color: "<< contacts[index].get_data_member("underwear_color") << "\n"
		<< " - darkest secret: "<< contacts[index].get_data_member("darkest_secret")<< "\n";
	}
	return (1);
}

/*
** Note(s) on search_cmd():
** 
** Function Summary:
** 1. check if there are any contacts
** 2. print contact list
** 3. prompt user for index of contact
** 
** Reason for "std::cin.clear();": without it, rampant spam ensues. Reason for
** "std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');":
** without it, a tiny amount of spam still slips through
*/

int search_cmd(contact_data contacts[], int &number_of_contacts)
{
	int requested_index;

	if (number_of_contacts == 0)
	{
		std::cout << "I apologize, but no contacts were found.\n";
		return (1);
	}
	print_contact_list(contacts, number_of_contacts);
	std::cout << "Enter the index number of the contact you wish to view: ";
	if (std::cin >> requested_index)
		process_index(contacts, number_of_contacts, requested_index);
	else if (std::cin.bad())
		std::cout << RED BOLD "cin error\n" RESET;
	else if (std::cin.eof())
		std::cout << RED BOLD "EOF reached\n" RESET;
	else
		std::cout << RED BOLD "A mishap. Retry, please.\n" RESET;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return (1);
}

/*
** Note(s) on add_cmd():
** 
** Function Summary:
** 1. check if contact list is full
** 2. prompt user for contact info
** 3. store user input
** 
** The shortening of first name, last name and nickname are done here instead
** of when the contact list is returned for the SEARCH command, because a
** contact is only added once, but it's likely to be displayed in the contact
** list many more times; so by doing a bit more work now, we save doing that
** bit of work over and over again later. 
** 
** "std::getline(std::cin, contacts[i].first_name);" Have to use getline()
** here, as spaces in the input shouldn't act as delimiters, which they do with
** cin().
*/

int add_cmd(contact_data contacts[], int &number_of_contacts)
{
	static int	i;
	std::string	tmp;

	if (number_of_contacts == MAX_CONTACTS)
	{
		std::cout << YELLOW BOLD "Contact limit reached. Upgrade to MASTER'S \
PHONEBOOK PRO to store EVEN MORE contacts! Now for only €99.99/month!\n" RESET;
		return (1);
	}
	std::cout << "Enter first name: ";
	std::getline(std::cin, tmp);
	contacts[i].set_data_member("first_name", tmp);
	if (tmp.size() > 10)
	{
		tmp.resize(9);
		tmp += '.';
	}
	contacts[i].set_data_member("first_name_short", tmp);

	std::cout << "Enter last name: ";
	std::getline(std::cin, tmp);
	contacts[i].set_data_member("last_name", tmp);
	if (tmp.size() > 10)
	{
		tmp.resize(9);
		tmp += '.';
	}
	contacts[i].set_data_member("last_name_short", tmp);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, tmp);
	contacts[i].set_data_member("nickname", tmp);
	if (tmp.size() > 10)
	{
		tmp.resize(9);
		tmp += '.';
	}
	contacts[i].set_data_member("nickname_short", tmp);

	std::cout << "Enter login: ";
	std::getline(std::cin, tmp);
	contacts[i].set_data_member("login", tmp);
	
	std::cout << "Enter postal address: ";
	std::getline(std::cin, tmp);
	contacts[i].set_data_member("postal_address", tmp);
	
	std::cout << "Enter email address: ";
	std::getline(std::cin, tmp);
	contacts[i].set_data_member("email_address", tmp);
	
	std::cout << "Enter phone number: ";
	std::getline(std::cin, tmp);
	contacts[i].set_data_member("phone_number", tmp);
	
	std::cout << "Enter birthday date: ";
	std::getline(std::cin, tmp);
	contacts[i].set_data_member("birthday_date", tmp);
	
	std::cout << "Enter favorite meal: ";
	std::getline(std::cin, tmp);
	contacts[i].set_data_member("favorite_meal", tmp);
	
	std::cout << "Enter underwear color: ";
	std::getline(std::cin, tmp);
	contacts[i].set_data_member("underwear_color", tmp);
	
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, tmp);
	contacts[i].set_data_member("darkest_secret", tmp);
	
	std::cout << GREEN BOLD "Contact saved, Glorious Master!\n" RESET;
	number_of_contacts++;
	i++;
	return (1);
}

int main()
{
	contact_data contacts[MAX_CONTACTS];
	std::string cmd;
	int number_of_contacts;
	
	welcome_message();
	number_of_contacts = 0;
	while (1)
	{
		std::cout << "\nWhat is your command, Master? : ";
		std::getline(std::cin, cmd);
		if (cmd.compare("EXIT") == 0 || cmd.compare("e") == 0)
		{
			std::cout << "I shall await your return, Magnificent Master.\n";
			break ;
		}
		else if (cmd.compare("ADD") == 0 || cmd.compare("a") == 0)
			add_cmd(contacts, number_of_contacts);
		else if (cmd.compare("SEARCH") == 0 || cmd.compare("s") == 0)
			search_cmd(contacts, number_of_contacts);
		else
			std::cout << "I do not comprehend, Wise Master.\n";
	}
	return (0);
}
