#pragma once
#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
 	private:

	public:
		//Constructor
		Cure(void);
		Cure(const Cure& copy);
		//Destructor
		~Cure(void);
		//Operator
		Cure &operator=(const Cure& copy);
		//AMateria member functions overloaded
		virtual AMateria *clone() const;
    	virtual void use(ICharacter &target);
};