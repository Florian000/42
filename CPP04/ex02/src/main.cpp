#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

int main()
{
Cat *C = new Cat();
Dog *D = new Dog();

std::cout << C->getType() << std::endl;
std::cout << D->getType() << std::endl;
C->makeSound();
D->makeSound();
return 0;
}