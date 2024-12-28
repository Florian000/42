#pragma once
#include <iostream>

class WrongAnimal
{
    protected: 
        std::string _type;
    public:
        WrongAnimal(void);
        virtual ~WrongAnimal(void);
        WrongAnimal(const WrongAnimal &copy);
        WrongAnimal &operator=(const WrongAnimal &copy);

        std::string getType()const;
        void makeSound()const;
};