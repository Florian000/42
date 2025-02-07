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

        float getRate(const std::string& date) const;

    private:
        std::map<std::string, float> exchangeRates;
        void loadRates(const std::string& filename);
};

#endif
