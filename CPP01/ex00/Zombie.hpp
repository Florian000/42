#include <iostream>

#pragma once

class Zombie{

    private:
        std::string _name;
    public:
        Zombie(std::string _name);
        ~Zombie(void);
        void announce(void);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );