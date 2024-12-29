#pragma once
#include <iostream>
#include "Animal.hpp"

class Cat: public Animal
{
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