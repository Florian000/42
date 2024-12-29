#pragma once
#include <iostream>

class WrongAnimal
{
    protected: 
        std::string _type;
    public:
        //constructor 
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal &copy);
        //Destructor
        virtual ~WrongAnimal(void);
        //Operator
        WrongAnimal &operator=(const WrongAnimal &copy);
        //Member function
        void makeSound()const;
        //Getter
        std::string getType()const;
};