
#include "../include/PmergeMe.hpp"

int main(int argc, char **argv) 
{
    if (argc < 2)
    { 
        std::cerr << "Error : Wrong number of arguments" << std::endl;
        return 1;
    }

    PmergeMe pmm;
    try
    {
        pmm.processInputAndSort(argc, argv); 
        pmm.displayResults();

    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl; 
        return 1;
    }
    return 0;
}