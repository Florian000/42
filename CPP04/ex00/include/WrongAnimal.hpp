#pragma once
#include <iostream>

class WrongAnimal
{
    protected: 
        std::string _type;
    public:
    WrongAnimal(void);
    virtual ~WrongAnimal(void);
    WrongAnimal(const WrongAnimal &WrongAnimal);
    WrongAnimal &operator=(const WrongAnimal &WrongAnimal);

    std::string getType()const;
    void makeSound()const;
};