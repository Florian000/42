#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamages = 20;
    _guarding = false;
    std::cout << "Scavtrap default constructor called" << std::endl;
    return ;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamages = 20;
    _guarding = false;
    std::cout << "Scavtrap name constructor called" << std::endl;
    return ;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
        _guarding = copy._guarding;
        std::cout << "Scavtrap copy constructor called" << std::endl;
        return;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& assigned)
{
    std::cout << "Scavtrap assignement operator called" << std::endl;
    _name = assigned._name;
    _energyPoints = assigned._energyPoints;
    _hitPoints = assigned._hitPoints;
    _guarding = assigned._guarding;
    _attackDamages = assigned._attackDamages;
    return *this; 
}

ScavTrap::~ScavTrap()
{
    std::cout << "Scavtrap destructor called" << std::endl;
    return ;
}

void ScavTrap::attack(const std::string& target)
{
    if(this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamages << " points of damage!" << std::endl;
        this->_energyPoints--;
    }
    else std::cout << "ScavTrap " << this->_name << " cannot attack because it has no hit points or energy points left." << std::endl;
    return ;
}

void ScavTrap::guardGate()
{
    if(this->_guarding == false)
    {
        this->_guarding = true;
        std::cout << "ScavTrap " << this->_name << " is now guarding the gate" << std::endl;
    }
    else
        std::cout << "ScavTrap " << this->_name << " is already guarding the gate" << std::endl;
}