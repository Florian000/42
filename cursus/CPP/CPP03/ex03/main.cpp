#include "DiamondTrap.hpp"

int main(void)
{
    std::cout << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "Creating a named DiamondTrap" << std::endl;
    std::cout << std::endl;
    DiamondTrap Diamondnamed("Diamond");
    std::cout << std::endl  <<"Creating a default DiamondTrap" << std::endl;
    std::cout << std::endl;
    DiamondTrap Diamondunknown;

    std::cout << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << std::endl  <<"Using named DiamondTrap" << std::endl;
    std::cout << std::endl;
    Diamondnamed.attack("target1");
    Diamondnamed.takeDamage(5);
    Diamondnamed.beRepaired(3);
    Diamondnamed.highFivesGuys();
    Diamondnamed.whoAmI();

    std::cout << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << std::endl  <<"Using unamed DiamondTrap" << std::endl;
    std::cout << std::endl;
    Diamondunknown.attack("target1");
    Diamondunknown.takeDamage(20);
    Diamondunknown.beRepaired(20);
    Diamondunknown.whoAmI();

    std::cout << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << std::endl  <<"Copying named DiamondTrap" << std::endl;
    std::cout << std::endl;
    DiamondTrap Diamondcopied(Diamondnamed);

    std::cout << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << std::endl  <<"Using copied DiamondTrap" << std::endl;
    std::cout << std::endl;
    Diamondcopied.attack("target1");
    Diamondcopied.takeDamage(5);
    Diamondcopied.beRepaired(3);
    Diamondcopied.highFivesGuys();
    Diamondcopied.whoAmI();

    std::cout << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << std::endl  <<"Assigning Diamondnamed to Diamondunknown" << std::endl;
    std::cout << std::endl;
    Diamondunknown = Diamondnamed;
    Diamondunknown.attack("target1");
    Diamondunknown.takeDamage(100);
    Diamondunknown.beRepaired(20);
    Diamondunknown.whoAmI();

    std::cout << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << std::endl  <<"Destruction of the three DiamondTrap created" << std::endl;
    std::cout << std::endl;
    return (0);
}