#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();

std::cout << "Type of j & i :" << std::endl;
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
std::cout << "Sound of Cat created as Animal :" << std::endl ;
i->makeSound();
std::cout << "Sound of Dog created as Animal :" << std::endl ;
j->makeSound();
std::cout << "Sound of Animal :" << std::endl ;
meta->makeSound();

const WrongAnimal* meta2 = new WrongAnimal();
const WrongAnimal* j2 = new WrongCat();
const WrongCat* i2 = new WrongCat();

std::cout << "Type of j2 & i2 :" << std::endl;
std::cout << j2->getType() << " " << std::endl;
std::cout << i2->getType() << " " << std::endl;
std::cout << "Sound of WrongCat created as wrongcat :" << std::endl ;
i2->makeSound();
std::cout << "Sound of WrongCat created as wrongAnimal :" << std::endl;
j2->makeSound();
std::cout << "Sound of WrongAnimal :" << std::endl;
meta2->makeSound();

delete meta;
delete i;
delete j;
delete meta2;
delete i2;
delete j2;
return 0;
}