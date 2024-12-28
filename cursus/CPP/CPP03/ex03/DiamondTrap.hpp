#pragma once
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
    private:
        std::string _name;
    public:
    DiamondTrap(void);
    DiamondTrap(const std::string name);
    DiamondTrap(const DiamondTrap& copy);
    DiamondTrap& operator=(const DiamondTrap& other);
    virtual ~DiamondTrap();

    void attack(const std::string& target);
    void whoAmI(void);
};