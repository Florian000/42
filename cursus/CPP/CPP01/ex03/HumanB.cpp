#include "Weapon.hpp"
#include "HumanB.hpp"
HumanB::HumanB(std::string name): _name(name)
{
    return ;
};
        
HumanB::~HumanB(void)
{
    return ;
};

void HumanB::attack(void) const
{
    if (this->_weapon == NULL)
        std::cout << this->_name << " No weapon available" << std::endl;
    else
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
};

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
};