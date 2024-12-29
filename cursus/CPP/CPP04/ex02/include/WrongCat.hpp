#pragma once
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    public:
        //constructor 
        WrongCat(void);
        WrongCat(const WrongCat &copy);
        //Destructor        
        ~WrongCat(void);
        //Operator
        WrongCat &operator=(const WrongCat &copy);
        //Member function
        void makeSound()const;
};