#pragma once
#include <iostream>
#include <AMateria.hpp>

class Cure : public AMateria
{
 	private:

	public:
		Cure(void);
		Cure(const Cure& copy);
		Cure &operator=(const Cure& copy);
		~Cure(void);
};