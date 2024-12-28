#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type)
{
    return ; 
};

Weapon::~Weapon(void)
{
    return ; 
};

const std::string& Weapon::getType(void) const
{
    return (this->_type);
};

void Weapon::setType(std::string const &type)
{
    this->_type = type;
}