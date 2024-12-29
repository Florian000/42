#pragma once
#include <iostream>

class Animal
{
    protected: 
        std::string _type;
    public:
        //constructor 
        Animal(void);
        Animal(const Animal &copy);
        //Destructor
        virtual ~Animal(void);
        //Operator
        Animal &operator=(const Animal &copy);
        //Member function
        virtual void makeSound()const;
        //Getter
        std::string getType()const;
};