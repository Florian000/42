/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:47:23 by fgranger          #+#    #+#             */
/*   Updated: 2025/01/27 17:47:30 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <limits>
#include <iomanip>
#include <sstream>
#include <cerrno>
#include <climits>
#include <cmath>

class ScalarConverter
{
    public:
        static void convert(const std::string& literal);
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);

        static void convertToChar(const std::string& literal);
        static void convertToInt(const std::string& literal);
        static void convertToFloat(const std::string& literal);
        static void convertToDouble(const std::string& literal);
        static bool handlePseudoLiterals(const std::string& literal);
};
