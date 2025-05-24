#include "../include/PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
        return (std::cerr << "Error: invalid argument" << std::endl, 1);

    PmergeMe pmm;
    try
    {
        pmm.processInput(argc, argv); 
        pmm.displayResults();
    }
    catch (const std::exception& e)
        { return (std::cerr << e.what() << std::endl, 1); }
    return 0;
}