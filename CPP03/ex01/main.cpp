#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "Creating a named ScavTrap" << std::endl;
    ScavTrap scavnamed("Scav");
    std::cout << std::endl  <<"Creating a default ScavTrap" << std::endl;
    ScavTrap scavunknown;

    std::cout << std::endl  <<"Using named ScavTrap" << std::endl;
    scavnamed.attack("target1");
    scavnamed.takeDamage(5);
    scavnamed.beRepaired(3);
    scavnamed.guardGate();

    std::cout << std::endl  <<"Using unamed ScavTrap" << std::endl;
    scavunknown.attack("target1");
    scavunknown.takeDamage(20);
    scavunknown.beRepaired(20);

    std::cout << std::endl  <<"Copying named ScavTrap" << std::endl;
    ScavTrap scavcopied(scavnamed);


    std::cout << std::endl  <<"Using copied ScavTrap" << std::endl;
    scavcopied.attack("target1");
    scavcopied.takeDamage(5);
    scavcopied.beRepaired(3);
    scavcopied.guardGate();

    std::cout << std::endl  <<"Assigneing Scavnamed to Scavunknown" << std::endl;
    scavunknown.attack("target1");
    scavunknown.takeDamage(100);
    scavunknown.beRepaired(20);
    
    std::cout << std::endl  <<"Destruction of the three ScavTrap created" << std::endl;

    return (0);
}