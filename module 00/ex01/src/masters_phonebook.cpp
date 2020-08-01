#include "masters_phonebook.hpp"

/*
Note(s) on print_contact_list():

Parent function: search_cmd
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
		<< std::setw(10) << contacts[j].first_name_short << "|"
		<< std::setw(10) << contacts[j].last_name_short << "|" 
		<< std::setw(10) << contacts[j].nickname_short << "\n"
		<< "–––––––––––––––––––––––––––––––––––––––––––\n";
	}
	return (1);
}

/*
Note(s) on process_index():

Parent function: search_cmd

Function Summary:
1. check if requested index number is valid
2. display contact info
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
		<< " - first name: "<< contacts[index].first_name << "\n"
		<< " - last name: "<< contacts[index].last_name << "\n"
		<< " - nickname: "<< contacts[index].nickname << "\n"
		<< " - login: "<< contacts[index].login << "\n"
		<< " - postal address: "<< contacts[index].postal_address << "\n"
		<< " - email address: "<< contacts[index].email_address << "\n"
		<< " - phone number: "<< contacts[index].phone_number << "\n"
		<< " - birthday date: "<< contacts[index].birthday_date << "\n"
		<< " - favorite meal: "<< contacts[index].favorite_meal << "\n"
		<< " - underwear color: "<< contacts[index].underwear_color << "\n"
		<< " - darkest secret: "<< contacts[index].darkest_secret << "\n\n";
	}
	return (1);
}

/*
Note(s) on search_cmd():

Function Summary:
1. check if there are any contacts
2. print contact list
3. prompt user for index of contact

Reason for "std::cin.clear();": without it, rampant spam ensues 
Reason for "std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');": without it, a tiny amount of spam still slips through
*/
int search_cmd(contact_data contacts[], int &number_of_contacts)
{
	int requested_index;

	if (number_of_contacts == 0)
	{
		std::cout << "I apologize, but no contacts were found..\n\n";
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
Note(s) on add_cmd():

Function Summary:
1. check is contact list is full
2. prompt user for contact info
3. store user input

It makes more sense to me to truncate the input of the first name, last name and nickname here (and store those shortened versions in an additional variable) instead of when the contact list is returned for the SEARCH command. A contact is only added once, but it's likely to be displayed in the contact list many more times; so by doing a bit more work now, we save doing that bit of work over and over again later. 

"std::getline(std::cin, contacts[i].first_name);" Have to use getline() here, as spaces in the input shouldn't act as delimiters, which they do with cin().
*/

int add_cmd(contact_data contacts[], int &number_of_contacts)
{
	static int i;

	if (number_of_contacts == 8)
	{
		std::cout << "Upgrade to MASTER'S PHONEBOOK PRO to store EVEN MORE \
		contacts! Now for only €99.99/month!\n(" BLACK "Conditions apply" RESET ")\n\n";
		return (1);
	}
	std::cout << "Enter first name: ";
	std::getline(std::cin, contacts[i].first_name);
	contacts[i].first_name_short = contacts[i].first_name;
	if (contacts[i].first_name.size() > 10)
	{
		contacts[i].first_name_short.resize(9);
		contacts[i].first_name_short += '.';
	}
	std::cout << "Enter last name: ";
	std::getline(std::cin, contacts[i].last_name);
	contacts[i].last_name_short = contacts[i].last_name;
	if (contacts[i].last_name.size() > 10)
	{
		contacts[i].last_name_short.resize(9);
		contacts[i].last_name_short += '.';
	}
	std::cout << "Enter nickname: ";
	std::getline(std::cin, contacts[i].nickname);
	contacts[i].nickname_short = contacts[i].nickname;
	if (contacts[i].nickname.size() > 10)
	{
		contacts[i].nickname_short.resize(9);
		contacts[i].nickname_short += '.';
	}
	// std::getline(std::cin, contacts[i].nickname);
	// std::cout << "Enter login: ";
	// std::getline(std::cin, contacts[i].login);
	// std::cout << "Enter postal address: ";
	// std::getline(std::cin, contacts[i].postal_address);
	// std::cout << "Enter email address: ";
	// std::getline(std::cin, contacts[i].email_address);
	// std::cout << "Enter phone number: ";
	// std::getline(std::cin, contacts[i].phone_number);
	// std::cout << "Enter birthday date: ";
	// std::getline(std::cin, contacts[i].birthday_date);
	// std::cout << "Enter favorite meal: ";
	// std::getline(std::cin, contacts[i].favorite_meal);
	// std::cout << "Enter underwear color: ";
	// std::getline(std::cin, contacts[i].underwear_color);
	// std::cout << "Enter darkest secret: ";
	// std::getline(std::cin, contacts[i].darkest_secret);
	std::cout << GREEN BOLD "Contact saved, Glorious Master!\n\n" RESET;
	number_of_contacts++;
	i++;
	return (1);
}

int main()
{
	contact_data contacts[8];
	std::string cmd;
	int number_of_contacts;
	
	welcome_message();
	number_of_contacts = 0;
	while (1)
	{
		std::cout << "Command me, Master: ";
		std::getline(std::cin, cmd);
		// else if (cmd.compare("EXIT") == 0)
		if (cmd.compare("EXIT") == 0 || cmd == "e") // TESTING: quicker cmd
		{
			std::cout << "I shall await your return, Magnificent Master.\n";
			break ;
		}
		// else if (cmd.compare("ADD") == 0)
		else if (cmd.compare("ADD") == 0 || cmd == "a") // TESTING: quicker cmd
			add_cmd(contacts, number_of_contacts);
		// else if (cmd.compare("SEARCH") == 0)
		else if (cmd.compare("SEARCH") == 0 || cmd == "s") // TESTING: quicker cmd
			search_cmd(contacts, number_of_contacts);
		else
			std::cout << "I do not comprehend, Wise Master\n";
	}
	return (0);
}