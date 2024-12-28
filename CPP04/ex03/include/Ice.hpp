#pragma once
#include <iostream>
#include <AMateria.hpp>

class Ice : public AMateria
{
	private:

	public:
		Ice(void);
		Ice(const Ice& copy);
		Ice &operator=(const Ice& copy);
		~Ice(void);
};