#pragma once
#include <iostream>
#include "Animal.hpp"

class Cat: public Animal
{
    public:
        Cat(void);
        virtual ~Cat(void);
        Cat(const Cat &copy);
        Cat &operator=(const Cat &copy);

        void makeSound()const;
};