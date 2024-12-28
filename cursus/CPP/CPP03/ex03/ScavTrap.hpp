#pragma once
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
    private:
        bool _guarding;
    public:
    ScavTrap(void);
    ScavTrap(const std::string name);
    ScavTrap(const ScavTrap& copy);
    ScavTrap& operator=(const ScavTrap& other);
    virtual ~ScavTrap();

    void attack(const std::string& target);
    void guardGate();
};