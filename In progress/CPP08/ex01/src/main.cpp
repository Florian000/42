#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../include/Span.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

void printSeparator(const std::string& description) {
    std::cout << BLUE << "==================== " << description << " ====================" << RESET << std::endl;
}

int main() {
    printSeparator("Subject tests");
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    printSeparator("Test with 10K+ random values");
    Span largeSpan(10000);
    std::srand(std::time(0));
    for (int i = 0; i < 10000; ++i) {
        largeSpan.addNumber(std::rand());
    }

    std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;

    printSeparator("Test with 20 random values");
    Span smallSpan(20);
    for (int i = 0; i < 20; ++i) {
        smallSpan.addNumber(std::rand());
    }

    std::cout << "Shortest span: " << smallSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << smallSpan.longestSpan() << std::endl;

    printSeparator("Test with addNumbers function (15000 random values)");
    Span rangeSpan(15000);
    std::vector<int> rangeValues;
    for (int i = 0; i < 15000; ++i) {
        rangeValues.push_back(std::rand());
    }
    rangeSpan.addNumbers(rangeValues.begin(), rangeValues.end());

    std::cout << "Shortest span: " << rangeSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << rangeSpan.longestSpan() << std::endl;

    printSeparator("Edge case: container full");
    try {
        Span fullSpan(3);
        fullSpan.addNumber(1);
        fullSpan.addNumber(2);
        fullSpan.addNumber(3);
        fullSpan.addNumber(4);
    } catch (const std::exception& e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    printSeparator("Edge case: empty container");
    try {
        Span emptySpan(5);
        std::cout << "Shortest span: " << emptySpan.shortestSpan() << std::endl; // This should throw an exception
    } catch (const std::exception& e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    printSeparator("Edge case: container with one value");
    try {
        Span oneValueSpan(5);
        oneValueSpan.addNumber(42);
        std::cout << "Shortest span: " << oneValueSpan.shortestSpan() << std::endl; // This should throw an exception
    } catch (const std::exception& e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    printSeparator("Edge case: addNumbers with too many values");
    try {
        Span limitedSpan(5);
        int arr[] = {1, 2, 3, 4, 5, 6};
        std::vector<int> tooManyValues(arr, arr + sizeof(arr) / sizeof(int));
        limitedSpan.addNumbers(tooManyValues.begin(), tooManyValues.end()); // This should throw an exception
    } catch (const std::exception& e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    return 0;
}
