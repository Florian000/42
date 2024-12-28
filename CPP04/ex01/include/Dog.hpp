#pragma once
#include <iostream>
#include "Animal.hpp"

class Dog: public Animal
{
    public:
    Dog(void);
    virtual ~Dog(void);
    Dog(const Dog &Dog);
    Dog &operator=(const Dog &Dog);

    void makeSound()const;
};