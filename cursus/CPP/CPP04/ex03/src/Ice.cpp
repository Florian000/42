#include "../include/Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	return ;
}

Ice::~Ice()
{
	return ;
}

Ice::Ice(Ice const &copy) : AMateria(copy)
{
	return ;
}

Ice &Ice::operator=(Ice const &copy)
{
    if (this != &copy) {
        _type = copy._type;
    }
    return *this;
}

AMateria *Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}