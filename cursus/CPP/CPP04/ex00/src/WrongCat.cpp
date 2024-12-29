#include "../include/WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
    _type = "WrongCat";
    std::cout << this->getType() <<" constructor called" << std::endl;
    return ;
}

WrongCat::~WrongCat(void)
{
    std::cout << this->getType() <<" destructor called" << std::endl;
    return ;
}

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal(copy)
{
    std::cout << this->getType() <<" copy constructor called" << std::endl;
    return ;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
    std::cout << "WrongCat assignement operator called" << std::endl;
    if(this == &copy)
        return (*this);
    _type = copy._type;
    return (*this);
}

void WrongCat::makeSound()const
{
    std::cout << "This " << this->getType() << " makes miaou" << std::endl;
    return ;
}