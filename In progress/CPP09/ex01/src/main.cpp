#include "../include/RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (std::cerr << "Error: Invalid argument" << std::endl, 1);

    std::string expression = argv[1];
    if (expression.empty())
        return (std::cerr << "Error: Invalid argument" << std::endl, 1);

    RPN calculator;
    try
    {
        long long result = calculator.calculate(expression);
        std::cout << result << std::endl;
    }
    catch (const std::exception& e)
        { return(std::cerr << e.what() << std::endl, 1); }
    return 0;
}
    