#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Unknown"), _hitPoints(10), _energyPoints(10), _attackDamages(0)
{
    std::cout << "ClapTrap " << "Unknown" << " created." << std::endl;
    return ;
};

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamages(0)
{
    std::cout << "ClapTrap " << name << " created." << std::endl;
    return ;
};

ClapTrap::ClapTrap(ClapTrap &claptrap): _name(claptrap._name),  _hitPoints(claptrap._hitPoints), _energyPoints(claptrap._energyPoints), _attackDamages(claptrap._attackDamages)
{
    std::cout << "ClapTrap " << claptrap._name << " copied." << std::endl;  
    return ;
};

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
    std::cout << "ClapTrap " << claptrap._name << " assigned." << std::endl;
    if (this != &claptrap)
    {
        this->_attackDamages = claptrap._attackDamages;
        this->_hitPoints = claptrap._hitPoints;
        this->_energyPoints = claptrap._energyPoints;
        this->_name = claptrap._name;
    }
    return (*this);
};

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap " << this->_name << " destroyed." << std::endl;
    return ;
};

void ClapTrap::attack(const std::string & target)
{
    if(this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamages << " points of damage!" << std::endl;
        this->_energyPoints--;
    }
    else std::cout << "ClapTrap " << this->_name << " cannot attack because it has no hit points or energy points left." << std::endl;
    return ;
};

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints > 0) 
    {
        if (amount > this->_hitPoints) this->_hitPoints = 0;
        else this->_hitPoints -= amount;
        std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage! Remaining hit points: " << this->_hitPoints << std::endl;
    } 
    else std::cout << "ClapTrap " << this->_name << " cannot take more damage because it has no hit points left." << std::endl;
    return ;
};

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0) 
    {
        this->_hitPoints += amount;
        this->_energyPoints--;
        std::cout << "ClapTrap " << this->_name << " repairs itself, recovering " << amount << " hit points! Remaining hit points: " << this->_hitPoints << ", remaining energy points: " << this->_energyPoints << std::endl;
    } 
    else std::cout << "ClapTrap " << this->_name << " cannot repair itself because it has no hit points or energy points left." << std::endl;
    return ;
};