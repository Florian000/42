#include "../include/Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain& copy)
{
	for(int i = 0; i < 100; i++)
		_ideas[i] = copy._ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(Brain &copy)
{
	for(int i = 0; i < 100; i++)
		_ideas[i] = copy._ideas[i];
	std::cout << "Assignement operator called" << std::endl;
	return(*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}