#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap diamond("Diamond");

    diamond.attack("target");
    diamond.takeDamage(30);
    diamond.beRepaired(20);
    diamond.guardGate();
    diamond.whoAmI();

    return 0;
}