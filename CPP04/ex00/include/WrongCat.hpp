#pragma once
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    public:
    WrongCat(void);
    virtual ~WrongCat(void);
    WrongCat(const WrongCat &WrongCat);
    WrongCat &operator=(const WrongCat &WrongCat);

    void makeSound()const;
};