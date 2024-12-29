#include "../include/Animal.hpp"

Animal::Animal(void)
{
    _type = "Unknown";
    std::cout << "Animal default constructor called" << std::endl;
    return ;
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called" << std::endl;
    return ;
}

Animal::Animal(const Animal &copy): _type(copy.getType())
{
    std::cout << "Animal copy constructor called" << std::endl;
    return ;
}

Animal &Animal::operator=(const Animal &copy)
{
    std::cout << "Animal assignement operator called" << std::endl;
    if (this == &copy)
        return (*this);
    this->_type = copy.getType();
    return (*this);
}

std::string Animal::getType()const
{
    return (this->_type);
}

void Animal::makeSound()const
{
    std::cout << "This Animal doesn't make sound" << std::endl;
    return ;
}