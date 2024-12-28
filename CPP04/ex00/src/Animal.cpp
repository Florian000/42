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

Animal::Animal(const Animal &Animal)
{
    this->_type = Animal._type;
    std::cout << "Animal copy constructor called" << std::endl;
    return ;
}
Animal &Animal::operator=(const Animal &Animal)
{
    std::cout << "Animal assignement operator called" << std::endl;
    if (this == &Animal)
        return (*this);
    this->_type = Animal._type;
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