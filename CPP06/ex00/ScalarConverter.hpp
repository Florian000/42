#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
public:
    static void convert(const std::string& literal);
private:
    ScalarConverter(); // Private constructor to prevent instantiation
    ~ScalarConverter(); // Private destructor
    ScalarConverter(const ScalarConverter&); // Private copy constructor
    ScalarConverter& operator=(const ScalarConverter&); // Private copy assignment operator

    static void convertToChar(const std::string& literal);
    static void convertToInt(const std::string& literal);
    static void convertToFloat(const std::string& literal);
    static void convertToDouble(const std::string& literal);
    static bool handlePseudoLiterals(const std::string& literal);
};

#endif // SCALARCONVERTER_HPP
