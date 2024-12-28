#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

int main()
{
const Animal *tab[100];

for (int i = 0; i < 100; i++)
{
	if (i % 2 == 0)
		tab[i] = new Cat();
	else
		tab[i] = new Dog();	
}

for (int i = 0; i < 100; i++)
{
	std::cout << "index :" << i << " Type :" << tab[i]->getType() << std::endl;
}

const Animal *copy = new Animal(*tab[0]);

for (int i = 0; i < 100; i++)
{
	delete tab[i];
}
std::cout << "Copy " << "Type :" << copy->getType() << std::endl;
delete copy;
return 0;
}