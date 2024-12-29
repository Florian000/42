#pragma once
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
	public:
		//Constructor
	    AMateria(std::string const &type);
		AMateria(AMateria const &copy);
		//Destructor
    	virtual ~AMateria();
		//OPerator
		AMateria &operator=(AMateria const &copy);
		//Getter
		std::string const & getType() const; //Returns the materia type
		//Member functions
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};