#pragma once
#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal
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