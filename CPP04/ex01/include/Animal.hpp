#pragma once
#include <iostream>

class Animal
{
    protected: 
        std::string _type;
    public:
        Animal(void);
        virtual ~Animal(void);
        Animal(const Animal &copy);
        Animal &operator=(const Animal &copy);

        std::string getType()const;
        virtual void makeSound()const;
};