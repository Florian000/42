#pragma once
#include <iostream>

class AAnimal
{
    protected: 
        std::string _type;
    public:
        //Constructor
        AAnimal(void);
        AAnimal(const AAnimal &copy);
        //Destructor
        virtual ~AAnimal(void);
        //Operator
        AAnimal &operator=(const AAnimal &copy);
        // Member function
        std::string getType()const ;
        virtual void makeSound()const = 0;
};