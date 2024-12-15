#include <iostream>

#pragma once

class Zombie{

    private:
        std::string _name;
    public:
        Zombie(void);
        Zombie(std::string _name);
        ~Zombie(void);

        void setzombie(std::string _name);
        void announce(void);
};

Zombie* zombieHorde( int N, std::string name );