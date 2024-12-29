#include "../include/MateriaSource.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        _materia[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
	{
        if (_materia[i])
            delete _materia[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++)
	{
        if (!_materia[i])
		{
            _materia[i] = m;
            return;
        }
    }
    std::cout << "Impossible to learn more Materia" << std::endl;
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
	{
        if (_materia[i] && _materia[i]->getType() == type)
            return _materia[i];
    }
    std::cout << "Impossible to create Materia (not learned)" << std::endl;
    return 0;
}