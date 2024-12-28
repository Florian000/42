#include "Harl.hpp"

void Harl::debug( void )
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do !" << std::endl << std::endl;
    return ;
}
void Harl::info( void )
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl << std::endl;
    return ;
}
void Harl::warning( void )
{
    std::cout << " [WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month." << std::endl << std::endl;
    return ;
}
void Harl::error( void )
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl << std::endl;
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
    const char* levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 5; i++) 
    {
        if ( i == 4 || level == levels[i])
        {
            switch (i)
            {
                case 0:
                    Harl::debug();
                case 1:
                    Harl::info();
                case 2:
                    Harl::warning();
                case 3:
                    Harl::error();
                    break;
                default:
                    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            }
            break;
        }
    }
}