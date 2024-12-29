#pragma once
#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
{
    private:
        Brain *_ideas;
    public:
        //Constructor
        Dog(void);
        Dog(const Dog &copy);
        //Destructor
        ~Dog(void);
        //Operator
        Dog &operator=(const Dog &copy);
        //Member functions
        void makeSound()const;
};