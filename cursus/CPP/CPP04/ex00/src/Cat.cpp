#include "../include/Cat.hpp"

Cat::Cat(void) : Animal()
{
    _type = "Cat";
    std::cout << this->getType() <<" constructor called" << std::endl;
    return ;
}

Cat::~Cat(void)
{
    std::cout << this->getType() <<" destructor called" << std::endl;
    return ;
}

Cat::Cat(const Cat &copy): Animal(copy)
{
    std::cout << this->getType() <<" copy constructor called" << std::endl;
    return ;
}

Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "Cat assignement operator called" << std::endl;
    if(this == &copy)
        return (*this);
    _type = copy._type;
    return (*this);
}

void Cat::makeSound()const
{
    std::cout << "This " << this->getType() << " makes miaou" << std::endl;
    return ;
}