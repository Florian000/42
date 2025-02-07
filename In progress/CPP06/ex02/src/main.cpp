#include "../include/functions.hpp"

int main() {
    // Test 1: Randomly generated object
    std::cout << BLUE << "Test 1: Randomly generated object" << RESET << std::endl;
    Base* base = generate();
    identify(base);
    identify(*base);
    delete base;

    std::cout << "-----------------------------" << std::endl;
    std::cout << GREEN << "Test 2: Specific object of type A" << RESET << std::endl;
    A a;
    identify(&a);
    identify(a);

    std::cout << "-----------------------------" << std::endl;
    std::cout << YELLOW << "Test 3: Specific object of type B" << RESET << std::endl;
    B b;
    identify(&b);
    identify(b);

    std::cout << "-----------------------------" << std::endl;
    std::cout << MAGENTA << "Test 4: Specific object of type C" << RESET << std::endl;
    C c;
    identify(&c);
    identify(c);

    std::cout << "-----------------------------" << std::endl;
    std::cout << RED << "Test 5: invalid base" << RESET << std::endl;
    Base* invalidBase = new Base();
    identify(invalidBase);
    identify(*invalidBase);
    delete invalidBase;

    std::cout << "-----------------------------" << std::endl;
    std::cout << CYAN << "Test 6: A to B or B to A or to C" << RESET << std::endl;
    Base* aToB = new A();
    identify(aToB);
    identify(*aToB);
    delete aToB;

    Base* bToC = new B();
    identify(bToC);
    identify(*bToC);
    delete bToC;

    Base* cToA = new C();
    identify(cToA);
    identify(*cToA);
    delete cToA;

    return 0;
}
