#pragma once
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
    private:
        Brain *_ideas;
    public:
        //constructor 
        Cat(void);
        Cat(const Cat &copy);
        //Destructor
        ~Cat(void);
        //Operator
        Cat &operator=(const Cat &copy);
        //Member function
        void makeSound()const;
};