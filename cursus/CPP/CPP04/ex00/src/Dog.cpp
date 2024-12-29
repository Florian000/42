#include "../include/Dog.hpp"

Dog::Dog(void) : Animal()
{
    _type = "Dog";
    std::cout << this->getType() <<" constructor called" << std::endl;
    return ;
}

Dog::~Dog(void)
{
    std::cout << this->getType() <<" destructor called" << std::endl;
    return ;
}

Dog::Dog(const Dog &copy): Animal(copy)
{
    std::cout << this->getType() <<" copy constructor called" << std::endl;
    return ;
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "Dog assignement operator called" << std::endl;
    if(this == &copy)
        return (*this);
    _type = copy._type;
    return (*this);
}

void Dog::makeSound()const
{
    std::cout << "This " << this->getType() << " makes wouf" << std::endl;
    return ;
}