#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap claptrap("Cliptrip");

    claptrap.attack("target1");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);

    claptrap.attack("target2");
    claptrap.takeDamage(8);
    claptrap.beRepaired(2);

    return (0);
}