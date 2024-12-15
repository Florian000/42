#include "Zombie.hpp"

Zombie::Zombie(std::string _name) : _name(_name)
{
    return;
};
Zombie::~Zombie(void)
{
    std::cout << "Destructor called : " << _name << " was deleted" << std::endl;
    return;
};

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return;
};