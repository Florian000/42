#include "../include/Character.hpp"
#include "../include/MateriaSource.hpp"
#include "../include/Cure.hpp"
#include "../include/Ice.hpp"

int main()
{
std::cout << "Subject main" << std::endl << std::endl;

IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
ICharacter* me = new Character("me");
AMateria* tmp;
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);
delete bob;
delete me;
delete src;

std::cout << std::endl << "Further tests " << std::endl << std::endl;

std::cout << std::endl << "Oveload learning materia " << std::endl << std::endl;

src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
src->learnMateria(new Ice());
src->learnMateria(new Cure());
src->learnMateria(new Ice());
delete src;

std::cout << std::endl << "Oveload inventory and use of wrong index" << std::endl << std::endl;

src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
me = new Character("me");
me->equip(src->createMateria("ice"));
me->equip(src->createMateria("ice"));
me->equip(src->createMateria("ice"));
me->equip(src->createMateria("ice"));
me->equip(src->createMateria("ice"));
bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);
me->use(2, *bob);
me->use(3, *bob);
me->use(4, *bob);
me->use(-1, *bob);
delete bob;
delete me;
delete src;

std::cout << std::endl << "Unexisting Materia" << std::endl << std::endl;

src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
me = new Character("me");
me->equip(src->createMateria("ic"));
me->equip(src->createMateria(""));
delete me;
delete src;

return 0;
}