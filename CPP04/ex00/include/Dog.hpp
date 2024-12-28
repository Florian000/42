#pragma once
#include <iostream>
#include "Animal.hpp"

class Dog: public Animal
{
    public:
        Dog(void);
        virtual ~Dog(void);
        Dog(const Dog &copy);
        Dog &operator=(const Dog &copy);

        void makeSound()const;
};