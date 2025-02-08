#include "../include/BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

BitcoinExchange::BitcoinExchange(const std::string& filename)
{
    loadRates(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : exchangeRates(other.exchangeRates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        exchangeRates = other.exchangeRates;
    return *this;
}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::loadRates(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");
    char delimiter = '|';
    std::string line;
    while (std::getline(file, line)) 
    {
        std::size_t delimiterPos = line.find(delimiter);
        if (delimiterPos == std::string::npos)
            exchangeRates[]
    }
}

float BitcoinExchange::getRate(const std::string& date) const
{
    std::map<std::string, float>::const_iterator it = exchangeRates.lower_bound(date);
    if (it == exchangeRates.end() || it->first != date)
    {
        if (it == exchangeRates.begin())
            return 0.0f;
        --it;
    }
    return it->second;
}

void BitcoinExchange::printTable() const
{
    for (std::map<std::string, float>::const_iterator it = exchangeRates.begin(); it != exchangeRates.end(); ++it)
    {
        std::cout << it->first << " => " << it->second << std::endl;

    }
}
