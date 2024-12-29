#pragma once
#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria *_inventory[4];

	public:
		//Constructor
		Character(std::string const &name);
		Character(Character const &copy);
		//Destructor
		virtual ~Character();
		//Operator
		Character &operator=(Character const &copy);
		//Member functions
		virtual std::string const &getName() const;
		virtual void equip(AMateria *m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter &target);
};