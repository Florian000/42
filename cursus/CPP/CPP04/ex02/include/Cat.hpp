#pragma once
#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal
{
    private:
        Brain *_ideas;
    public:
        //Constructor
        Cat(void);
        Cat(const Cat &copy);
        //Destructor
        ~Cat(void);
        //Operator
        Cat &operator=(const Cat &copy);
        //Member functions
        void makeSound()const;
};