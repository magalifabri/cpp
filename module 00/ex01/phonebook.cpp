#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <unistd.h>

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
// your excellence / holiness
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

int add_cmd(contact_data contacts[], int &number_of_contacts)
{
	static int i;

	// FULL
	if (number_of_contacts == 8)
	{
		std::cout << "Upgrade to EPIC FONEBUK PRO to store EVEN MORE contacts! Now for only €99.99/month!\n(Conditions apply)\n\n";
		return (1);
	}
	// PROMPT user for contact info
	std::cout << "Enter first name: ";
	std::cin >> contacts[i].first_name;
	contacts[i].first_name_short = contacts[i].first_name;
	if (contacts[i].first_name.size() > 10)
	{
		contacts[i].first_name_short.resize(9);
		contacts[i].first_name_short += '.';
	}
	std::cout << "Enter last name: ";
	std::cin >> contacts[i].last_name;
	contacts[i].last_name_short = contacts[i].last_name;
	if (contacts[i].last_name.size() > 10)
	{
		contacts[i].last_name_short.resize(9);
		contacts[i].last_name_short += '.';
	}
	std::cout << "Enter nickname: ";
	std::cin >> contacts[i].nickname;
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
	std::cout << B_GREEN << "Contact saved, Highest Highness.\n\n" << RESET;
	number_of_contacts++;
	i++;
	return (1);
}


int main()
{
	contact_data contacts[8];
	// int i;
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
	// i = 0;
	std::string cmd;
	while (1)
	{
		// PROMPT the user for input
		std::cout << "Command me, Divine Overlord: ";
		std::cin >> cmd;

		// CHECK what the input contains
		if (cmd.compare("EXIT") == 0 || cmd == "e") // TESTING: quicker cmd
		{
			std::cout << "I will be here upon your return, Magnificent Master.\n";
			break ;
		}
		// Note: It makes more sense to me to truncate the input of the first name, last name and nickname here instead of when the contact list is returned for the SEARCH command. Because a contact is only added once, but it's likely to be displayed in the contact list many more times; so by doing a bit more work now, we save doing that bit of work over an over again in the future. Also, I see no point in having the full names stored in memory, when they will never be displayed anyway and also serve no other purpose.
		
		// ADD
		else if (cmd.compare("ADD") == 0 || cmd == "a") // TESTING: quicker cmd
		{
			add_cmd(contacts, number_of_contacts);
			// // std::cout << "add command given\n"; // TESTING
			// // FULL
			// if (number_of_contacts == 8)
			// 	std::cout << "Upgrade to EPIC FONEBUK PRO to store EVEN MORE contacts! Now for only €99.99/month!\n (Conditions apply)\n\n";
			// // PROMPT user for contact info
			// std::cout << "Enter first name: ";
			// std::cin >> contacts[i].first_name;
			// contacts[i].first_name_short = contacts[i].first_name;
			// if (contacts[i].first_name.size() > 10)
			// {
			// 	contacts[i].first_name_short.resize(9);
			// 	contacts[i].first_name_short += '.';
			// }
			// std::cout << "Enter last name: ";
			// std::cin >> contacts[i].last_name;
			// contacts[i].last_name_short = contacts[i].last_name;
			// if (contacts[i].last_name.size() > 10)
			// {
			// 	contacts[i].last_name_short.resize(9);
			// 	contacts[i].last_name_short += '.';
			// }
			// std::cout << "Enter nickname: ";
			// std::cin >> contacts[i].nickname;
			// contacts[i].nickname_short = contacts[i].nickname;
			// if (contacts[i].nickname.size() > 10)
			// {
			// 	contacts[i].nickname_short.resize(9);
			// 	contacts[i].nickname_short += '.';
			// }
			// // std::cin >> contacts[i].nickname;
			// // std::cout << "Enter login: ";
			// // std::cin >> contacts[i].login;
			// // std::cout << "Enter postal address: ";
			// // std::cin >> contacts[i].postal_address;
			// // std::cout << "Enter email address: ";
			// // std::cin >> contacts[i].email_address;
			// // std::cout << "Enter phone number: ";
			// // std::cin >> contacts[i].phone_number;
			// // std::cout << "Enter birthday date: ";
			// // std::cin >> contacts[i].birthday_date;
			// // std::cout << "Enter favorite meal: ";
			// // std::cin >> contacts[i].favorite_meal;
			// // std::cout << "Enter underwear color: ";
			// // std::cin >> contacts[i].underwear_color;
			// // std::cout << "Enter darkest secret: ";
			// // std::cin >> contacts[i].darkest_secret;
			// std::cout << B_GREEN << "Contact saved, Highest Highness.\n\n" << RESET;
			// number_of_contacts++;
			// i++;
		}
		
		// SEARCH
		// else if (cmd.compare("SEARCH") == 0)
		else if (cmd.compare("SEARCH") == 0 || cmd == "s") // TESTING: quicker cmd
		{
			if (number_of_contacts == 0)
				std::cout << "I apologize, but no contacts were found..\n\n";
			else
			{
				// PRINT contact list
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
					<< std::setw(10) << contacts[j].nickname_short << "\n";
				}
				// PROMPT user for index of contact & process it
				std::cout << "Enter the index number of the contact you wish to view: ";
				int requested_index_number;
				if (std::cin >> requested_index_number)
				{
					// CHECK if requested index number is valid
					// std::cout << "You requested: " << requested_index_number << "\n";
					if (requested_index_number < 0 || requested_index_number > number_of_contacts - 1)
						std::cout << "A number above -1 and below " << number_of_contacts << " would be most delightful.\n";
					// DISPLAY contact info
					else
					{
						std::cout << "Behold! The contact information for index number " << requested_index_number << ": \n";
						std::cout << " - first name: " << contacts[requested_index_number].first_name << "\n";
						std::cout << " - last name: " << contacts[requested_index_number].last_name << "\n";
						std::cout << " - nickname: " << contacts[requested_index_number].nickname << "\n";
						std::cout << " - login: " << contacts[requested_index_number].login << "\n";
						std::cout << " - postal address: " << contacts[requested_index_number].postal_address << "\n";
						std::cout << " - email address: " << contacts[requested_index_number].email_address << "\n";
						std::cout << " - phone number: " << contacts[requested_index_number].phone_number << "\n";
						std::cout << " - birthday date: " << contacts[requested_index_number].birthday_date << "\n";
						std::cout << " - favorite meal: " << contacts[requested_index_number].favorite_meal << "\n";
						std::cout << " - underwear color: " << contacts[requested_index_number].underwear_color << "\n";
						std::cout << " - darkest secret: " << contacts[requested_index_number].darkest_secret << "\n\n";
					}
					//
				}
				else if (std::cin.bad())
					std::cout << "IO error\n";
				else if (std::cin.eof())
					std::cout << "EOF reached (perhaps combined with a format problem)\n";
				else
				{
					std::cout << "format problem\n";
					std::cin.clear(); // without it, rapid spam ensues 
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}
		}
		else
			std::cout << "I do not comprehend, Oh Wise One\n";
	}
}