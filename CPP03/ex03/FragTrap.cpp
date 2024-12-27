#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamages = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
    return ;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamages = 30;
    std::cout << "FragTrap name constructor called" << std::endl;
    return ;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
        std::cout << "FragTrap copy constructor called" << std::endl;
        return;
}

FragTrap &FragTrap::operator=(const FragTrap& assigned)
{
    std::cout << "FragTrap assignement operator called" << std::endl;
    _name = assigned._name;
    _energyPoints = assigned._energyPoints;
    _hitPoints = assigned._hitPoints;
    _attackDamages = assigned._attackDamages;
    return *this; 
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
    return ;
}

void FragTrap::attack(const std::string& target)
{
    if(this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamages << " points of damage!" << std::endl;
        this->_energyPoints--;
    }
    else std::cout << "FragTrap " << this->_name << " cannot attack because it has no hit points or energy points left." << std::endl;
    return ;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "High Five from " << this->_name << std::endl;
    return ;
}
