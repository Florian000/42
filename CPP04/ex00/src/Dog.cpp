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

Dog::Dog(const Dog &Dog): Animal(Dog)
{
    std::cout << this->getType() <<" copy constructor called" << std::endl;
    return ;
}
Dog &Dog::operator=(const Dog &Dog)
{
    std::cout << "Dog assignement operator called" << std::endl;
    if(this == &Dog)
        return (*this);
    _type = Dog._type;
    return (*this);
}

void Dog::makeSound()const
{
    std::cout << "This " << this->getType() << " makes wouf" << std::endl;
    return ;
}