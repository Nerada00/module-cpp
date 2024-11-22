#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream> 
#include <stdexcept>


enum    e_err {
    OK,
    KO
};


class BitcoinExchange {

    private:

        std::string _inputFile;
        std::map<std::string, float> _data;

        bool parseDate(const std::string &date);
        bool parseValue(const std::string &value);
        bool bissextileDate(int year);
        float findClosestRate(const std::string &date);
        void loadDataFile(const std::string &dataFile);

    public:

        BitcoinExchange();
        BitcoinExchange(char *fileName);
        BitcoinExchange(BitcoinExchange const &src);
        ~BitcoinExchange();
        BitcoinExchange &operator=(BitcoinExchange const &rhs);
        void processFile();
        std::ifstream *openFile(const std::string &filename);
};