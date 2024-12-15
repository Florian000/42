#include "Zombie.hpp"

int main(void)
{
    Zombie *zombies;
    int N = 1000;

    std::cout << "BRAINZ !" << std::endl;

    std::cout << "Creating "<< N << " zombies named Bob" << std::endl;
    zombies = zombieHorde(N, "Bob");
    std::cout << "checking announce for each" << std::endl;
    for (int i = 0; i < N; i ++)
        zombies[i].announce();
    std::cout << "deleting the zombies" << std::endl;

    delete [] zombies;
    return (0);
}