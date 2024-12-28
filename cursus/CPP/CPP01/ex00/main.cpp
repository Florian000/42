#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie;

    std::cout << "BRAINZ !" << std::endl;

    std::cout << "Usage of newZombie : "<< std::endl;
    zombie = newZombie("bob");
    zombie->announce();
    delete zombie;

    std::cout << std::endl << "Usage of randomChump : " << std::endl;
    randomChump("bob");

    return (0);
}