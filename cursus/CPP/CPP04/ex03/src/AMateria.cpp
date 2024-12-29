#include "../include/AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type)
{
	return ;
}

AMateria::~AMateria()
{
	return ;
}

AMateria::AMateria(AMateria const &copy) : _type(copy._type)
{
	return ;
}

AMateria &AMateria::operator=(AMateria const &copy)
{
    if (this != &copy) {
        _type = copy._type;
    }
    return *this;
}

std::string const &AMateria::getType() const
{
    return _type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "* uses " << _type << " on " << target.getName() << " *" << std::endl;
}