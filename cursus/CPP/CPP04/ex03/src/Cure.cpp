#include "../include/Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	return ;
}

Cure::~Cure()
{
	return ;
}

Cure::Cure(Cure const &copy) : AMateria(copy)
{
	return ;
}

Cure &Cure::operator=(Cure const &copy)
{
    if (this != &copy) {
        _type = copy._type;
    }
    return *this;
}

AMateria *Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}