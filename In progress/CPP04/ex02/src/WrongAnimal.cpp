#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    _type = "Unknown";
    std::cout << "WrongAnimal default constructor called" << std::endl;
    return ;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    this->_type = copy._type;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    return ;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
    std::cout << "WrongAnimal assignement operator called" << std::endl;
    if (this == &copy)
        return (*this);
    this->_type = copy._type;
    return (*this);
}

std::string WrongAnimal::getType()const
{
    return (this->_type);
}

void WrongAnimal::makeSound()const
{
    std::cout << "This WrongAnimal doesn't make sound" << std::endl;
    return ;
}