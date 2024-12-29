#include "../include/AAnimal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

int main()
{
const Cat *tabcat[50];
const Dog *tabdog[50];

for (int i = 0; i < 50; i++)
{
		tabcat[i] = new Cat();
		tabdog[i] = new Dog();	
}

for (int i = 0; i < 50; i++)
{
	std::cout << "index :" << i << " Type :" << tabcat[i]->getType() << std::endl;
	std::cout << "index :" << i << " Type :" << tabdog[i]->getType() << std::endl;
}

Cat *cat = new Cat();
Cat copycat = *cat;
Cat *catcat = new Cat(*cat);
for (int i = 0; i < 50; i++)
{
	delete tabcat[i];
	delete tabdog[i];
}
delete cat;
std::cout << "Copycat " << "Type :" << copycat.getType() << std::endl;
std::cout << "Catcat " << "Type :" << catcat->getType() << std::endl;
delete catcat;
return 0;
}