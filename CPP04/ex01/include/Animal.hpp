#pragma once
#include <iostream>

class Animal
{
    protected: 
        std::string _type;
    public:
    Animal(void);
    virtual ~Animal(void);
    Animal(const Animal &Animal);
    Animal &operator=(const Animal &Animal);

    std::string getType()const;
    virtual void makeSound()const;
};