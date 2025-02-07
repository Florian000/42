#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "../include/easyfind.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

int main() {
        std::vector<int> vec;
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }
    std::cout << BLUE << "Testing vector:" << RESET << std::endl;
    std::cout << "Expecting to find 5" << std::endl;
    try {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << GREEN << "Found: " << *it << RESET << std::endl;
    } catch (const std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << "Expecting to throw an exception for 42" << std::endl;
    try {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << GREEN << "Found: " << *it << RESET << std::endl;
    } catch (const std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    std::cout << YELLOW << "------------------------" << RESET << std::endl;
        std::list<int> lst;
    for (int i = 0; i < 10; ++i) {
        lst.push_back(i);
    }
    std::cout << BLUE << "Testing list:" << RESET << std::endl;
    std::cout << "Expecting to find 5" << std::endl;
    try {
        std::list<int>::iterator it = easyfind(lst, 5);
        std::cout << GREEN << "Found: " << *it << RESET << std::endl;
    } catch (const std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << "Expecting to throw an exception for 42" << std::endl;
    try {
        std::list<int>::iterator it = easyfind(lst, 42);
        std::cout << GREEN << "Found: " << *it << RESET << std::endl;
    } catch (const std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    std::cout << YELLOW << "------------------------" << RESET << std::endl;
        std::deque<int> deq;
    for (int i = 0; i < 10; ++i) {
        deq.push_back(i);
    }
    std::cout << BLUE << "Testing deque:" << RESET << std::endl;
    std::cout << "Expecting to find 5" << std::endl;
    try {
        std::deque<int>::iterator it = easyfind(deq, 5);
        std::cout << GREEN << "Found: " << *it << RESET << std::endl;
    } catch (const std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << "Expecting to throw an exception for 42" << std::endl;
    try {
        std::deque<int>::iterator it = easyfind(deq, 42);
        std::cout << GREEN << "Found: " << *it << RESET << std::endl;
    } catch (const std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    return 0;
}
