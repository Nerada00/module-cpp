#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <map>

enum    e_err {
    OK,
    KO
};

class BitcoinExchange {

    private:
        std::ifstream openFile(const std::string &filename);
        bool parseDate(const std::string &date);
        bool bissextileDate(int year);
        bool parseValue(const std::string &value);
        float findClosestRate(const std::string &date);
        std::string _inputFile;
        std::map<std::string, float> _data; 

    public:
        BitcoinExchange();
        BitcoinExchange(char *fileName);
        BitcoinExchange(BitcoinExchange const &src);
        ~BitcoinExchange();
        BitcoinExchange &operator=(BitcoinExchange const &rhs);
        void loadDataFile(const std::string &dataFile);
        void processFile();


};