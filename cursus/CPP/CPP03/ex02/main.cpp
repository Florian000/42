#include "FragTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
    std::cout << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "Creating a named FragTrap" << std::endl;
    std::cout << std::endl;
    FragTrap Fragnamed("Frag");
    std::cout << std::endl  <<"Creating a default FragTrap" << std::endl;
    std::cout << std::endl;
    FragTrap Fragunknown;

    std::cout << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << std::endl  <<"Using named FragTrap" << std::endl;
    std::cout << std::endl;
    Fragnamed.attack("target1");
    Fragnamed.takeDamage(5);
    Fragnamed.beRepaired(3);
    Fragnamed.highFivesGuys();

    std::cout << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << std::endl  <<"Using unamed FragTrap" << std::endl;
    std::cout << std::endl;
    Fragunknown.attack("target1");
    Fragunknown.takeDamage(20);
    Fragunknown.beRepaired(20);

    std::cout << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << std::endl  <<"Copying named FragTrap" << std::endl;
    std::cout << std::endl;
    FragTrap Fragcopied(Fragnamed);

    std::cout << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << std::endl  <<"Using copied FragTrap" << std::endl;
    std::cout << std::endl;
    Fragcopied.attack("target1");
    Fragcopied.takeDamage(5);
    Fragcopied.beRepaired(3);
    Fragcopied.highFivesGuys();

    std::cout << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << std::endl  <<"Assigning Fragnamed to Fragunknown" << std::endl;
    std::cout << std::endl;
    Fragunknown = Fragnamed;
    Fragunknown.attack("target1");
    Fragunknown.takeDamage(100);
    Fragunknown.beRepaired(20);

    std::cout << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << std::endl  <<"Destruction of the three FragTrap created" << std::endl;
    std::cout << std::endl;
    return (0);
}