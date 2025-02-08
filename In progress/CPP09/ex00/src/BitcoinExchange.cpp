#include "../include/BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

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
        throw std::runtime_error("Error: could not open data.csv file.");
    try
    {
    char delimiter = ',';
    std::string line;
    while (std::getline(file, line)) 
    {
        std::size_t delimiterPos = line.find(delimiter);
        if (delimiterPos != std::string::npos)
        {
            std::string date = line.substr(0, delimiterPos);
            std::string value = line.substr(delimiterPos + 1);
            exchangeRates[date] = static_cast<float>(std::atof(value.c_str()));
        }
    }
    }
    catch (const std::exception& e)
    {
        throw std::runtime_error("Error reading csv file :" + std::string(e.what()));
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
void BitcoinExchange::printRates() const
{
    for (std::map<std::string, float>::const_iterator it = exchangeRates.begin(); it != exchangeRates.end(); ++it)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}

void BitcoinExchange::readInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open input file.");
    char delimiter = '|';
    std::string line;
    while (std::getline(file, line)) 
    {
        std::size_t delimiterPos = line.find(delimiter);
        if (delimiterPos != std::string::npos)
        {
            std::string date = line.substr(0, delimiterPos);
            date = trim(date);
            std::string value = line.substr(delimiterPos + 1);
            value = trim(value);
            if (date == "date" && value == "value")
                continue;
            if (value.find_first_not_of("0123456789.-") != std::string::npos)
            {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            if (value.empty())
            {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            float valueFloat = static_cast<float>(std::atof(value.c_str()));
            if (valueFloat == 0.0f && value.find_first_not_of("0. ") != std::string::npos)
            {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            if (checkDate(date) && checkValue(valueFloat))
            {
                    std::cout << date << " => " << valueFloat << " => " << getRate(date) * valueFloat << std::endl;
            }
        }
        else
        {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
}

std::string& BitcoinExchange::trim(std::string& str) const
{
    size_t start = str.find_first_not_of(" \t\r\n");
    if (start != std::string::npos)
        str = str.substr(start);
    else {
        str.clear();
        return str;
    }

    size_t end = str.find_last_not_of(" \t\r\n");
    if (end != std::string::npos)
        str = str.substr(0, end + 1);
    
    return str;
}

bool BitcoinExchange::checkDate(const std::string& date) const
{
    if (date.size() != 10)
    {
        std::cerr << "Error: wrong date format = > " << date << std::endl;
        return false;
    }
    if (date[4] != '-' || date[7] != '-')
    {
        std::cerr << "Error: wrong date format => " << date << std::endl;
        return false;
    }
    for (size_t i = 0; i < date.size(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
        {
            std::cerr << "Error: wrong date format => " << date << std::endl;
            return false;
        }
    }
    return true;
}

bool BitcoinExchange::checkValue(const float &value) const
{
    if (value < 0)
    {
        std::cerr << "Error: not a positive number" << std::endl;
        return false;
    }
    else if (value > 1000)
    {
        std::cerr << "Error: too large number" << std::endl;
        return false;
    }
    return true;
}

