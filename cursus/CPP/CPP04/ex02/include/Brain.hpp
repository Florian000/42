#pragma once
#include <iostream>
class Brain
{
	private:
		std::string _ideas[100];
	public:
		//Constructor
		Brain(void);
		Brain(Brain &copy);
		//Destructor
		~Brain(void);
		//Operator
		Brain &operator=(Brain &brain);
};
