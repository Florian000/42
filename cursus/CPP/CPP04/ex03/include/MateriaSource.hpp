#pragma once
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _materia[4];

	public:
		// Constructor
		MateriaSource();
		//Destructor
		virtual ~MateriaSource();

		// Member functions from IMateriaSource
		virtual void learnMateria(AMateria* m);
		virtual AMateria* createMateria(std::string const & type);
};