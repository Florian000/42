#pragma once
#include <iostream>

class AAnimal
{
    protected: 
        std::string _type;
    public:
        AAnimal(void);
        virtual ~AAnimal(void);
        AAnimal(const AAnimal &copy);
        AAnimal &operator=(const AAnimal &copy);

        std::string getType()const ;
        virtual void makeSound()const = 0;
};