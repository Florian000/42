#include "../include/Cat.hpp"

Cat::Cat(void) : Animal()
{
    _type = "Cat";
    _ideas = new Brain();
    std::cout << this->getType() <<" constructor called" << std::endl;
    return ;
}

Cat::~Cat(void)
{
    delete _ideas;
    std::cout << this->getType() <<" destructor called" << std::endl;
    return ;
}

Cat::Cat(const Cat &copy): Animal(copy), _ideas(new Brain(*copy._ideas))
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
    _ideas = _ideas = new Brain(*copy._ideas);
    return (*this);
}

void Cat::makeSound()const
{
    std::cout << "This " << this->getType() << " makes miaou" << std::endl;
    return ;
}