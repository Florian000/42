#pragma once
#include <iostream>
#include "Animal.hpp"

class Cat: public Animal
{
    public:
    Cat(void);
    virtual ~Cat(void);
    Cat(const Cat &cat);
    Cat &operator=(const Cat &cat);

    void makeSound()const;
};