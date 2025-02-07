#include <iostream>
#include <list>
#include "../include/MutantStack.hpp"
#include "../include/MutantStack.tpp"

// ANSI escape codes for colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

template <typename T>
void compareWithList(const MutantStack<T>& mstack, const std::list<T>& lst) {
    if (std::equal(mstack.begin(), mstack.end(), lst.begin())) {
        std::cout << GREEN << "MutantStack and std::list match." << RESET << std::endl;
    } else {
        std::cout << RED << "MutantStack and std::list do not match." << RESET << std::endl;
    }
}

int main() {
    // Create a MutantStack and a std::list of integers
    std::cout << CYAN << "Creating a MutantStack and a std::list of integers." << RESET << std::endl;
    MutantStack<int> mstack;
    std::list<int> lst;

    // Edge test: Iterate over an empty stack
    std::cout << CYAN << "Iterating over an empty stack:" << RESET << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << RED << *it << RESET << std::endl;
    }
    compareWithList(mstack, lst);

    // Push elements onto the stack and list
    std::cout << CYAN << "Pushing elements onto the stack and list: 5, 17, 3, 5, 737, 0" << RESET << std::endl;
    mstack.push(5);
    lst.push_back(5);
    mstack.push(17);
    lst.push_back(17);
    mstack.push(3);
    lst.push_back(3);
    mstack.push(5);
    lst.push_back(5);
    mstack.push(737);
    lst.push_back(737);
    mstack.push(0);
    lst.push_back(0);

    // Print the elements of the stack using iterators
    std::cout << CYAN << "Iterating through the stack and printing each element:" << RESET << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << GREEN << *it << RESET << std::endl;
    }
    compareWithList(mstack, lst);

    // Demonstrate reverse iteration
    std::cout << CYAN << "Iterating through the stack in reverse order and printing each element:" << RESET << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << YELLOW << *rit << RESET << std::endl;
    }
    if (std::equal(mstack.rbegin(), mstack.rend(), lst.rbegin())) {
        std::cout << GREEN << "Reverse iteration of MutantStack and std::list match." << RESET << std::endl;
    } else {
        std::cout << RED << "Reverse iteration of MutantStack and std::list do not match." << RESET << std::endl;
    }

    // Edge test: Pop elements and iterate
    std::cout << CYAN << "Popping elements and iterating:" << RESET << std::endl;
    mstack.pop(); lst.pop_back();
    mstack.pop(); lst.pop_back();
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << GREEN << *it << RESET << std::endl;
    }
    compareWithList(mstack, lst);

    // Edge test: Iterate after clearing the stack
    std::cout << CYAN << "Clearing the stack and iterating:" << RESET << std::endl;
    while (!mstack.empty()) {
        mstack.pop();
    }
    lst.clear();
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << RED << *it << RESET << std::endl;
    }
    compareWithList(mstack, lst);

    return 0;
}
