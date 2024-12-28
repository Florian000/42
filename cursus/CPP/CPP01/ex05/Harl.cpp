#include "Harl.hpp"

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do !" << std::endl;
    return ;
}
void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
    return ;
}
void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month." << std::endl;
    return ;
}
void Harl::error( void )
{
    std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
    return ;
}
Harl::Harl(void)
{
    return ;
}
Harl::~Harl(void)
{
    return ;
}
void Harl::complain(std::string level)
{
    std::string complain[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*f[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    
    for (int i = 0; i < 4; i++)
    {
        if (level == complain[i])
        {
            (this->*f[i])();
            return ;
        }
    }
    std::cout << "[ Probably complaining about insignificant problems ]"<< std::endl;
    return ;
}