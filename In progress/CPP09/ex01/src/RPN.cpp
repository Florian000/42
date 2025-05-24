#include "../include/RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : _operands(other._operands) {}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        _operands = other._operands;
    return *this;
}

RPN::~RPN() {}

void RPN::clearStack()
{
    while (!_operands.empty())
        _operands.pop();
}

bool RPN::isOperator(const std::string& token) const {return token == "+" || token == "-" || token == "*" || token == "/";}

long long RPN::performOperation(const std::string& op, long long val1, long long val2)
{
    if (op == "+") return val1 + val2;
    if (op == "-") return val1 - val2;
    if (op == "*") return val1 * val2;
    if (op == "/")
    {
        if (val2 == 0)
            throw std::runtime_error("Error: Division by zero.");
        return val1 / val2;
    }
    throw std::runtime_error("Error: Invalid operator.");
}

long long RPN::calculate(const std::string& expression)
{
    clearStack();

    std::stringstream ss(expression);
    std::string token;

    while (ss >> token)
    {
        if (token.length() == 1 && std::isdigit(static_cast<unsigned char>(token[0])))
            _operands.push(token[0] - '0');
        else if (isOperator(token))
        {
            if (_operands.size() < 2)
                throw std::runtime_error("Error: Not enough operands for operation.");
            long long val2 = _operands.top(); _operands.pop();
            long long val1 = _operands.top(); _operands.pop();
            _operands.push(performOperation(token, val1, val2));
        }
        else
            throw std::runtime_error("Error: Invalid token.");
    }
    if (_operands.size() != 1)
        throw std::runtime_error("Error: The user input is not a valid RPN expression.");
    return _operands.top();
}