#pragma once

#include <string>
#include <stack>
#include <sstream>
#include <iostream>

class RPN
{
    private:
        std::stack<long long> _operands;

        bool isOperator(const std::string& token) const;
        long long performOperation(const std::string& op, long long val1, long long val2);
        void clearStack();

    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        long long calculate(const std::string& expression);
};