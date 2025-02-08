#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: wrong number of arguments \n Usage : ./btc <file>" << std::endl;
        return 1;
    }
    (void)argv;
    try
    {
        BitcoinExchange exchange("data.csv");
        exchange.readInput(argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}
