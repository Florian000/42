#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange exchange("bitcoin_data.csv");
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string date, valueStr;
        if (std::getline(iss, date, '|') && std::getline(iss, valueStr)) {
            try {
                std::stringstream valueStream(valueStr);
                float value;
                valueStream >> value;
                if (valueStream.fail() || !valueStream.eof()) {
                    throw std::invalid_argument("Invalid float");
                }
                if (value < 0 || value > 1000) {
                    std::cerr << "Error: value out of range." << std::endl;
                } else {
                    float rate = exchange.getRate(date);
                    std::cout << date << " => " << value << " = " << value * rate << std::endl;
                }
            } catch (const std::exception& e) {
                std::cerr << "Error: invalid value." << std::endl;
            }
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
    return 0;
}
