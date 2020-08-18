#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << CYAN "default constructor: MateriaSource\n" RESET;
	learnedMateria[0] = nullptr;
	learnedMateria[1] = nullptr;
	learnedMateria[2] = nullptr;
	learnedMateria[3] = nullptr;
}
MateriaSource::~MateriaSource(void)
{
	std::cout << MAGENTA "destructor: MateriaSource\n" RESET;
	int i = -1;
	while (++i < 4)
	{
		if (learnedMateria[i] != nullptr)
		{
			delete learnedMateria[i];
			learnedMateria[i] = nullptr;
		}
	}
}
void MateriaSource::learnMateria(AMateria *materia)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (learnedMateria[i] == materia)
		{
			std::cout << RED "This exact Materia has already been learned\n" RESET;
			return ;
		}
	}
	i = -1;
	while (++i < 4)
	{
		if (learnedMateria[i] == nullptr)
		{
			learnedMateria[i] = materia;
			std::cout << "Materia, " << materia->getType() << ", learned and stored in slot " << i << "\n";
			return ;
		}
	}
	std::cout << RED "Materia, " << materia->getType() << ", could not be learned: all storage slots used.\n"
	<< "Deleting it\n" RESET;
	delete materia;
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = -1;
	while (++i < 4)
	{
		if (learnedMateria[i] && type == learnedMateria[i]->getType())
		{
			AMateria *newMateria = learnedMateria[i]->clone();
			std::cout << "Materia of type '" << type << "' created\n";
			return (newMateria);
		}
	}
	std::cout << RED "failed to create Materia: type not amongst learned Materia\n" RESET;
	return (nullptr);
}
