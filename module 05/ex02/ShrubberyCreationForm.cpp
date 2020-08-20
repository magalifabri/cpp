#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &targetParam)
{
	std::cout << CYAN "constructor: ShrubberyCreationForm with target: " << targetParam << "\n" RESET;
	target = targetParam;
	setName("Shrubbery Creation Form");
	setGradeNeededToSign(145);
	setGradeNeededToExecute(137);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << MAGENTA "destructor: ShrubberyCreationForm\n" RESET;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream newFile;

	std::cout << executor.getName() << ": 'Checking if form is signed..'\n";
	if (getSignedStatus() == 1)
		std::cout << executor.getName() << ": 'Affirmative! Good job, boy.' * pats you on the head *\n";
	else
	{
		std::cout << executor.getName() << ": 'Negative! Beat it, scrub!'\n";
		return ;
	}
	
	std::cout << executor.getName() << ": 'Let's get this show on the road!' * grabs a garden spade *\n";
	newFile.open(target + (std::string)"_shrubbery");
	newFile
<< "                                                                       \n"
<< "                    #######%####   #%%#%######                         \n"
<< "             ######%%%%%%%%%%%%%%%#%%%%%%%%###########                 \n"
<< "        ########%######%%%%%%%%%%%%#####%%%%%%%%%%%%%%####             \n"
<< "         ###%%%%%%%%%%%%###%%%%%%###%%%%###%##%%%#########             \n"
<< "       ######%%%%%%%#####%%#########%%%%%%%%%#%%%###%%%####            \n"
<< "      #####%%%%%%##%%%%%%%%%%%%%%%%#%%%%%#%%%%%%%%%%%%%#######         \n"
<< "        ############%%%%%%%%%%%%%%%%%%%%%%#%###%%%%%%%####%%###        \n"
<< "    ##############%%########%%%%###%%%%%%%%%%%############%%#####      \n"
<< " %#####%##%###%%%%%%%%%%##%%%%%%#############%%%%%###%%%%%#########    \n"
<< "#######%%%%%%%%%%%%%%%%%###########%%#%%%%%########%%%#####%%%%%%%##   \n"
<< "######%%%%%%%#######%%%%%%###%%%%%%%%%%%##%%%%%%%%%%###%%%%%%%%%%%%%###\n"
<< "#####%%%%%%%%##%%%%#%##%#%%%%%%%%%%%##%%%%%%##%%%%####%%%%%%%%%%%%%%#  \n"
<< "    #####%%%&#%%%%%%%%%%####%#%%%%%%%%%%%%%%%%%%%%%%%##%%%%%%%%%%%%%%%#\n"
<< "      %%%%%%%&&&%%%%%%%%%%%%%%%#%%%%%%%%%%%%%%%%%%%%  &%%%%%%%%%%%%    \n"
<< "                 %%&&&&%%%%&&&&&&&&&&&&&&&&&%%%%&  &&&&&&              \n"
<< "                    %%%%&&%%&&&%%&&&%&%%%%&&% %&%&&&                   \n"
<< "                       %%%&&%   %%&&&&    && %%&&&                     \n"
<< "                          %%%%&&&&&&     %&&&%&&                       \n"
<< "                              %&&&&&     &&%&&                         \n"
<< "                               &%%&&&   %&&&&                          \n"
<< "                                 &%%%&& %&&&                           \n"
<< "                                   %&%&&&&&                            \n"
<< "                                   #%%%&&&&                            \n"
<< "                                    %%&&&&&                            \n"
<< "                                   %%&&&&&&                            \n"
<< "                                  %&&&&&&&&&                           \n"
<< "                                %&%%&&&&&&&&&&&                        \n";
                                                                           
	std::cout << executor.getName() << ": 'All done! Enjoy your new, magnificent tree in " << target << "!\n";
}