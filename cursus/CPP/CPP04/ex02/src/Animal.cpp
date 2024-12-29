#include "../include/AAnimal.hpp"

AAnimal::AAnimal(void)
{
    _type = "Unknown";
    std::cout << "Animal default constructor called" << std::endl;
    return ;
}

AAnimal::~AAnimal(void)
{
    std::cout << "Animal destructor called" << std::endl;
    return ;
}

AAnimal::AAnimal(const AAnimal &copy): _type(copy.getType())
{
    std::cout << "Animal copy constructor called" << std::endl;
    return ;
}
AAnimal &AAnimal::operator=(const AAnimal &copy)
{
    std::cout << "Animal assignement operator called" << std::endl;
    if (this == &copy)
        return (*this);
    this->_type = copy.getType();
    return (*this);
}

std::string AAnimal::getType()const
{
    return (this->_type);
}

void AAnimal::makeSound()const
{
    std::cout << "This Animal doesn't make sound" << std::endl;
    return ;
}