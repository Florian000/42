/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:47:43 by fgranger          #+#    #+#             */
/*   Updated: 2025/01/27 17:47:47 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }

void ScalarConverter::convert(const std::string& literal)
{
    if (handlePseudoLiterals(literal))
        return;
    if (literal.length() > 1 && !std::isdigit(literal[0]) && literal[0] != '-' && literal[0] != '+')
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
    else
    {
        convertToChar(literal);
        convertToInt(literal);
        convertToFloat(literal);
        convertToDouble(literal);
    }
}

bool ScalarConverter::handlePseudoLiterals(const std::string& literal)
{
    if (literal == "-inff" || literal == "+inff" || literal == "nanf" || literal == "inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
        return true;
    }
    if (literal == "-inf" || literal == "+inf" || literal == "nan" || literal == "inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
        return true;
    }
    return false;
}

void ScalarConverter::convertToChar(const std::string& literal)
{
    try
    {
        if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
            std::cout << "char: '" << static_cast<char>(literal[0]) << "'" << std::endl;
        else
        {
            long i = std::strtol(literal.c_str(), NULL, 10);
            if (errno == ERANGE || i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
                std::cout << "char: impossible" << std::endl;
            else if (!std::isprint(static_cast<char>(i)))
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
        }
    } 
    catch (...) 
    {
        std::cout << "char: impossible" << std::endl;
    }
}

void ScalarConverter::convertToInt(const std::string& literal)
{
    long i;
    
    try
    {
        if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
            i = static_cast<int>(literal[0]);
        else
            i = std::strtol(literal.c_str(), NULL, 10);
        if (errno == ERANGE || i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(i) << std::endl;
    }
    catch (...)
    {
        std::cout << "int: impossible" << std::endl;
    }
}

void ScalarConverter::convertToFloat(const std::string& literal)
{
    float f;
    
    try
    {
        if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
            f = static_cast<float>(literal[0]);
        else
            f = static_cast<float>(std::atof(literal.c_str()));
        if (f < -std::numeric_limits<float>::max() || f > std::numeric_limits<float>::max() || std::numeric_limits<float>::digits10 <= std::log10(std::abs(f)))
            std::cout << "float: impossible" << std::endl;
        else
            std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    }
    catch (...)
    {
        std::cout << "float: impossible" << std::endl;
    }
}

void ScalarConverter::convertToDouble(const std::string& literal)
{
    double d;

    try
    {
        if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
            d = static_cast<double>(literal[0]);
        else
            d = std::strtod(literal.c_str(), NULL);
        if (d < -std::numeric_limits<double>::max() || d > std::numeric_limits<double>::max() || std::numeric_limits<double>::digits10 <= std::log10(std::abs(d)))   
            std::cout << "double: impossible" << std::endl;
        else
            std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    }
    catch (...)
    {
        std::cout << "double: impossible" << std::endl;
    }
}
