#pragma once
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    public:
        WrongCat(void);
        virtual ~WrongCat(void);
        WrongCat(const WrongCat &copy);
        WrongCat &operator=(const WrongCat &copy);

        void makeSound()const;
};