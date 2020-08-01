#include "../masters_phonebook.hpp"

void welcome_message(void)
{
	std::cout << YELLOW BOLD
	<< "   ╔╦╗╔═╗╔═╗╔╦╗╔═╗╦═╗'╔═╗\n"
	<< "   ║║║╠═╣╚═╗ ║ ║╣ ╠╦╝ ╚═╗\n"
	<< "   ╩ ╩╩ ╩╚═╝ ╩ ╚═╝╩╚═ ╚═╝\n"
	<< "   ╔═╗╦ ╦╔═╗╔╗╔╔═╗╔╗ ╔═╗╔═╗╦╔═\n"
	<< "   ╠═╝╠═╣║ ║║║║║╣ ╠╩╗║ ║║ ║╠╩╗\n"
	<< "   ╩  ╩ ╩╚═╝╝╚╝╚═╝╚═╝╚═╝╚═╝╩ ╩\n"
	<< "=================================\n\n" RESET
	<< BOLD
	<< "COMMANDS: \n"
	<< "- to add a contact: ADD\n"
	<< "- to search for a contact: SEARCH\n"
	<< "- to exit: EXIT\n"
	<< "_________________________________\n" RESET;
}
