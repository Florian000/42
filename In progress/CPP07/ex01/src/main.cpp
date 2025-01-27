#include <iostream>
#include "../include/iter.hpp"

class Awesome {
 public:
  Awesome(void) : _n(42) { return; }
  int get(void) const { return this->_n; }

 private:
  int _n;
};

std::ostream& operator<<(std::ostream& o, Awesome const& rhs) {
  o << rhs.get();
  return o;
}

template <typename T>
void print(const T& x) {
  std::cout << x << std::endl;
  return;
}

int main()
{
    int tab[] = {0, 1, 2, 3, 4};  // <--- I never understood why you can't write
                                    // int[] tab. Wouldn't that make more sense?
    Awesome tab2[5];

    iter(tab, 5, print);
    iter(tab2, 5, print);

    int intArray[] = {1, 2, 3, 4, 5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    std::string strArray[] = {"Hello", "World", "!"};

    std::cout << "Int array: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;
    std::cout << "Incremented int array: ";
    iter(intArray, 5, incrementElement<int>);
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;
    std::cout << "Decremented int array: ";
    iter(intArray, 5, decrementElement<int>);
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    std::cout << "Char array: ";
    iter(charArray, 5, printElement<char>);
    std::cout << std::endl;
    std::cout << "Incremented char array: ";
    iter(charArray, 5, incrementElement<char>);
    iter(charArray, 5, printElement<char>);
    std::cout << std::endl;
    std::cout << "Decremented char array: ";
    iter(charArray, 5, decrementElement<char>);
    iter(charArray, 5, printElement<char>);
    std::cout << std::endl;

    std::cout << "String array: ";
    iter(strArray, 3, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}
