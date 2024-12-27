#pragma once
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
    public:
    FragTrap(void);
    FragTrap(const std::string name);
    FragTrap(const FragTrap& copy);
    FragTrap& operator=(const FragTrap& other);
    ~FragTrap();

    void attack(const std::string& target);
    void highFivesGuys(void);
};