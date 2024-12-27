#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "Creating a named FragTrap" << std::endl;
    FragTrap fragnamed("frag");
    std::cout << std::endl  <<"Creating a default FragTrap" << std::endl;
    FragTrap fragunknown;

    std::cout << std::endl  <<"Using named FragTrap" << std::endl;
    fragnamed.attack("target1");
    fragnamed.takeDamage(5);
    fragnamed.beRepaired(3);
    fragnamed.highFivesGuys();

    std::cout << std::endl  <<"Using unamed FragTrap" << std::endl;
    fragunknown.attack("target1");
    fragunknown.takeDamage(20);
    fragunknown.beRepaired(20);

    std::cout << std::endl  <<"Copying named FragTrap" << std::endl;
    FragTrap fragcopied(fragnamed);


    std::cout << std::endl  <<"Using copied FragTrap" << std::endl;
    fragcopied.attack("target1");
    fragcopied.takeDamage(5);
    fragcopied.beRepaired(3);
    fragcopied.highFivesGuys();

    std::cout << std::endl  <<"Assigneing fragnamed to fragunknown" << std::endl;
    fragunknown.attack("target1");
    fragunknown.takeDamage(100);
    fragunknown.beRepaired(20);
    
    std::cout << std::endl  <<"Destruction of the three FragTrap created" << std::endl;

    return (0);
}