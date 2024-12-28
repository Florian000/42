#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Unknown_clap_name"), _name("Unknown")
{
    _hitPoints = 100;
    _attackDamages = 30;
    _energyPoints = 50;
    std::cout << "DiamondTrap " << _name << " constructed." << std::endl;
    return ;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), _name(name)
{
    _hitPoints = 100;
    _attackDamages = 30;
    _energyPoints = 50;
    std::cout << "DiamondTrap " << name << " constructed." << std::endl;
    return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
    std::cout << "DiamondTrap " << _name << " copy constructed." << std::endl;
    return ;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other) {
        ClapTrap::operator=(other);
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
       _name = other._name;
    }
    std::cout << "DiamondTrap " << _name << " assigned." << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _name << " destructed." << std::endl;
    return ;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
    return ;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << _name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}