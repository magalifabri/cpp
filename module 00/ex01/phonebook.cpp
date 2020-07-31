#include <iostream>
#include <iomanip>
#include <string>
#include <unistd.h>
#include <sstream>


#define RED "\033[0;31m"	
#define B_RED "\033[1;31m"	
#define GREEN "\033[0;32m"	
#define B_GREEN "\033[1;32m"	
#define YELLOW "\033[0;33m"	
#define B_YELLOW "\033[01;33m"	
#define BLUE "\033[0;34m"	
#define B_BLUE "\033[1;34m"	
#define MAGENTA "\033[0;35m"	
#define B_MAGENTA "\033[1;35m"	
#define CYAN "\033[0;36m"	
#define B_CYAN "\033[1;36m"	
#define RESET "\033[0m"	

/*
Bold: \u001b[1m
Underline: \u001b[4m
Reversed: \u001b[7m
*/

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

void loading()
{
	int i = 0;
    std::cout << "Loading...\n";
	while (i++ < 100)
	{
		usleep(10000);
		write(1, "\033[1000D", 8);
		std::cout << i << std::flush;
		std::cout << "%";
	}
	std::cout << "\n";
}

int main()
{
	contact_data contacts[8];
	int i;
	int j;
	int number_of_contacts;
	number_of_contacts = 0;

	// loading();

	// welcome message
	std::cout << "Welcome to" << "\n"
 	<< " ___ ___ ___ ___" << "\n"
 	<< "| __| _ \\_ _/ __|" << "\n"
 	<< "| _||  _/| | (__ " << "\n"
 	<< "|___|_| |___\\___|" << "\n"
 	<< " ___  ___  _  _ ___ ___ _   _ _  __" << "\n"
 	<< "| __|/ _ \\| \\| | __| _ ) | | | |/ /" << "\n"
 	<< "| _|| (_) | .` | _|| _ \\ |_| | ' < " << "\n"
 	<< "|_|  \\___/|_|\\_|___|___/\\___/|_|\\_\\ !!!" << "\n"
	<< "_,.-*~*-.,__,.-*~*-.,__,.-*~*-.,__,.-" << "\n"
	<< "\n"
	// explain how the phonebook works
	<< "To add a contact, write 'ADD'\n"
	<< "To search for a contact, write 'SEARCH'\n"
	<< "TO exit, write 'EXIT'\n"
	<< "\n";
	i = 0;
	while (1)
	{
		std::string cmd;
		// prompt the user for input
		std::cout << "Command me, Divine Overlord: ";
		// std::cin.sync();
		// std::cin.clear();
		// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		// store the input
		std::cin >> cmd;
		// check what the input contains
		if (cmd.compare("EXIT") == 0 || cmd == "e") // TESTING: quicker cmd
		{
			std::cout << "I will be here upon your return, Magnificent Master.\n";
			break ;
		}
		// Note: It makes more sense to me to truncate the input of the first name, last name and nickname here instead of when the contact list is returned for the SEARCH command. Because a contact is only added once, but it's likely to be displayed in the contact list many more times; so by doing a bit more work now, we save doing that bit of work over an over again in the future. Also, I see no point in having the full names stored in memory, when they will never be displayed anyway and also serve no other purpose.
		else if (cmd.compare("ADD") == 0 || cmd == "a") // TESTING: quicker cmd
		{
			std::cout << "add command given\n"; // TESTING
			std::cout << "Enter first name: ";
			std::cin.ignore();
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
			// std::cin >> contacts[i].nickname;
			// std::cout << "Enter login: ";
			// std::cin >> contacts[i].login;
			// std::cout << "Enter postal address: ";
			// std::cin >> contacts[i].postal_address;
			// std::cout << "Enter email address: ";
			// std::cin >> contacts[i].email_address;
			// std::cout << "Enter phone number: ";
			// std::cin >> contacts[i].phone_number;
			// std::cout << "Enter birthday date: ";
			// std::cin >> contacts[i].birthday_date;
			// std::cout << "Enter favorite meal: ";
			// std::cin >> contacts[i].favorite_meal;
			// std::cout << "Enter underwear color: ";
			// std::cin >> contacts[i].underwear_color;
			// std::cout << "Enter darkest secret: ";
			// std::cin >> contacts[i].darkest_secret;
			// std::cout << "The contact " << first_name << " " << last_name << " with the phone number " << phone_number << " has been added to the phone book\n";
			std::cout << "Contact saved, Highest Highness.\n\n";
			number_of_contacts++;
			i++;
		}
		// else if (cmd.compare("SEARCH") == 0)
		else if (cmd.compare("SEARCH") == 0 || cmd == "s") // TESTING: quicker cmd
		{
			// std::cout << "search command given\n";
			if (number_of_contacts == 0)
				std::cout << B_RED"I apologize, but no contacts were found..\n\n\033[0m";
			else
			{
				// print contact list
				std::cout << "The following contacts were found:\n\n";
				i = -1;
				std::cout
				<< std::setw(10) << "Index"
				<< "|"
				<< std::setw(10) << "First name"
				<< "|"
				<< std::setw(10) << "Last name"
				<< "|" 
				<< std::setw(10) << "Nickname"
				<< "\n"
				<< "–––––––––––––––––––––––––––––––––––––––––––\n";
				j = -1;
				while (++j < number_of_contacts)
				{
					std::cout
					<< std::setw(10) << j
					<< "|"
					<< std::setw(10) << contacts[j].first_name_short
					<< "|"
					<< std::setw(10) << contacts[j].last_name_short
					<< "|" 
					<< std::setw(10) << contacts[j].nickname_short << "\n";
				}
				// prompt user for index of contact
				std::cout << "Enter the index number of the contact you wish to view: ";
				std::string input;
				int requested_index_number;
				std::cin.clear();
				std::getline(std::cin, input);
				std::stringstream(input) >> requested_index_number;
				// std::cin >> requested_index_number;
				std::cout << requested_index_number << "\n";
				if (requested_index_number < 0 && requested_index_number > 9)
					std::cout << "I apologize, but that is not a number\n";
				else if (requested_index_number > number_of_contacts - 1)
					std::cout << "I'm sorry, there is no contact by that index number, Great Lord.\n";
				else
				{
					std::cout << "You requested: " << requested_index_number << "\n";
					
				}
			}
			
		}
		else
			std::cout << "I do not comprehend, Oh Wise One\n";
		//		to add a contact: write "ADD" (without the quotations marks). Afterwards the user is prompted for a first name, a last name and a phone number
		sleep(1);
		//		to view a contact's number: write "SEARCH". Afterwards the user is prompted for a first name and then a last name. If a match if found, the phone number is returned, otherwise an error is returned
		//		to exit: write "EXIT"
		// compare input to ADD, SEARCH and EXIT
		// if ADD: 
		//		if 8 contacts are already present, deny request
		//		if not, prompt user for more info
		// if SEARCH: prompt user for more info, then look up a match
		// if EXIT: exit
	}
}