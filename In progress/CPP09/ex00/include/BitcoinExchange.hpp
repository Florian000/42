#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
    public:
        BitcoinExchange(const std::string& filename);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
        void readInput(const std::string& filename);
    private:
        std::map<std::string, float> exchangeRates;
        void loadRates(const std::string& filename);
        float getRate(const std::string& date) const;
        std::string& trim(std::string& str) const;
        void printRates() const;
        bool checkDate(const std::string& date) const;
        bool checkValue(const float& value) const;
};

#endif
