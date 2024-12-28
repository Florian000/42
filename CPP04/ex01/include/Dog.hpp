#pragma once
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
    private:
        Brain *_ideas;
    public:
        Dog(void);
        virtual ~Dog(void);
        Dog(const Dog &copy);
        Dog &operator=(const Dog &copy);

        void makeSound()const;
};