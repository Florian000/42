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

WrongAnimal::WrongAnimal(const WrongAnimal &WrongAnimal)
{
    this->_type = WrongAnimal._type;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    return ;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &WrongAnimal)
{
    std::cout << "WrongAnimal assignement operator called" << std::endl;
    if (this == &WrongAnimal)
        return (*this);
    this->_type = WrongAnimal._type;
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