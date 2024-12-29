#pragma once
#include <iostream>
#include "Animal.hpp"

class Dog: public Animal
{
    public:
        //constructor 
        Dog(void);
        Dog(const Dog &copy);
        //Destructor
        ~Dog(void);
        //Operator
        Dog &operator=(const Dog &copy);
        //Member function
        void makeSound()const;
};