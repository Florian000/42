#include "ClapTrap.hpp"

int main(void)
{
    std::cout << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "testing ClapTrap with named constructor <cliptrip>" << std::endl;
    std::cout << std::endl;
    ClapTrap claptrap("Cliptrip");
    claptrap.attack("target1");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);
    claptrap.attack("target2");
    claptrap.takeDamage(8);
    claptrap.beRepaired(2);

    std::cout << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "testing ClapTrap with named constructor <unknown>" << std::endl;
    std::cout << std::endl;
    ClapTrap clap2;
    clap2.attack("target1");
    clap2.takeDamage(5);
    clap2.beRepaired(3);

    std::cout << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "testing ClapTrap with copy from clap2 <unknown>" << std::endl;
    std::cout << std::endl;
    ClapTrap clap3(clap2);
    clap3.attack("target1");
    clap3.takeDamage(5);
    clap3.beRepaired(3);
    clap3.attack("target2");
    clap3.takeDamage(8);
    clap3.beRepaired(2);

    std::cout << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "testing ClapTrap with assignement from claptrap <cliptrip>" << std::endl;
    std::cout << std::endl;
    ClapTrap clap4 = claptrap;
    clap3.attack("target1");
    clap3.takeDamage(5);
    clap3.beRepaired(3);

    std::cout << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "end of the program destroyin <cliptrip> <unknown> copy of <unknown> and copy by assignement of <cliptrip>" << std::endl;
    std::cout << std::endl;
    return (0);
}