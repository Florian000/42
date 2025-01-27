
#include "../includes/phonebook.hpp"

void display_line(std::string str, int mode)
{
    size_t len;

    len = str.length();
    switch (mode)
    {
        case CENTER:
            std::cout << B_WHI GREN"| " << (SIZE > len?std::string((SIZE - len) / 2, ' '):"") << str << (SIZE > len ? std::string((SIZE - len) / 2 + (SIZE - len) % 2, ' '):"") << " |" << RSET << std::endl;
            break;
        case RIGHT:
            std::cout << B_WHI GREN"| " << str << (SIZE > len?std::string(SIZE - len, ' ') : "")  << " |" << RSET << std::endl;
            break;
        case LEFT:
            std::cout << B_WHI GREN"| " << (SIZE > len?std::string(SIZE - len, ' ') : "") << str << " |" << RSET << std::endl;
            break;
        case SEP:
            std::cout << B_WHI GREN"| " << (SIZE > len? std::string(SIZE - len, '_'):"")<< str << " |" << RSET << std::endl;
            break;
        case INPUT :
            std::cout << B_WHI GREN"| " << str << RSET;
            break;
        case ERROR :
            std::cout << B_RED << str << std::endl << RSET;
            break;
        case HEADER :
            std::cout << CLEAR;
            std::cout << " " << std::string(SIZE +2, '_') << RSET <<std::endl;
            std::cout << B_WHI GREN"| " << std::string(SIZE, ' ') << " |" << RSET << std::endl;
            std::cout << B_WHI GREN"| " << std::string((SIZE - len) / 2, ' ') << str << std::string((SIZE - len) / 2 + (SIZE - len) % 2, ' ') << " |" << RSET << std::endl;
            std::cout << B_WHI GREN"| " << std::string(SIZE, '_') << " |" << RSET << std::endl;
            break;
    }
}

void app_start(void)
{
    display_line("PHONEBOOK APP", HEADER);
    display_line("Welcome to the Phonebook app !", RIGHT);
    display_line("You can use the following commands : ", RIGHT);
    display_line("- ADD", RIGHT);
    display_line("- SEARCH", RIGHT);
    display_line("- EXIT", RIGHT);
    display_line("", SEP);
    display_line("", CENTER);
}