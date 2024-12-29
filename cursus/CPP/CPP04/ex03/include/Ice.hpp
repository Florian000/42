#pragma once
#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
	private:

	public:
		//Constructor
		Ice(void);
		Ice(const Ice& copy);
		//Destructor
		~Ice(void);
		//Operator
		Ice &operator=(const Ice& copy);
		//AMateria member functions
		virtual AMateria *clone() const;
    	virtual void use(ICharacter &target);
};