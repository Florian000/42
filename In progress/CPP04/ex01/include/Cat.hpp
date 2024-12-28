#pragma once
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
    private:
        Brain *_ideas;
    public:
        Cat(void);
        virtual ~Cat(void);
        Cat(const Cat &copy);
        Cat &operator=(const Cat &copy);

        void makeSound()const;
};