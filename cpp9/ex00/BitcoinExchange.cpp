#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(char *fileName) : _inputFile(fileName) {}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) { *this = src; }
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
    if (this != &rhs) {
        this->_inputFile = rhs._inputFile;
        this->_data = rhs._data;
    }
    return (*this);
}

std::ifstream BitcoinExchange::openFile(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }
    return (file);
}

bool BitcoinExchange::parseDate(const std::string &date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') 
        return (false);

    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));

    if (month < 1 || month > 12)
        return (false);

    const int validDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && bissextileDate(year)) {
        if (day < 1 || day > 29)
            return (false);
    } else if (day < 1 || day > validDay[month - 1]) {
        return (false);
    }
    return (true);
}

bool BitcoinExchange::bissextileDate(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool BitcoinExchange::parseValue(const std::string &value) {
    try {
        float num = std::stof(value);
        if (num < 0 || num > 1000)
            return (false);
    } catch (...) {
        return (false);
    }
    return (true);
}

float BitcoinExchange::findClosestRate(const std::string &date) {
    std::map<std::string, float>::iterator it = _data.lower_bound(date);

    if (it == _data.end() || it->first != date) {
        if (it == _data.begin())
            throw std::runtime_error("Error: no earlier date available.");
        --it;
    }
    return (it->second);
}

void BitcoinExchange::loadDataFile(const std::string &dataFile) {
    std::ifstream file = openFile(dataFile);
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) 
            continue;

        size_t sepPos = line.find(',');
        if (sepPos == std::string::npos) {
            std::cerr << "Error: bad data file input => " << line << '\n';
            continue;
        }

        std::string date = line.substr(0, sepPos);
        std::string rateStr = line.substr(sepPos + 1);

        if (!parseDate(date)) {
            std::cerr << "Error: bad date in data file => " << date << '\n';
            continue;
        }

        try {
            float rate = std::stof(rateStr);
            if (rate < 0) {
                std::cerr << "Error: invalid rate => " << rateStr << '\n';
                continue;
            }
            _data[date] = rate;
        } 
        catch (...) 
        {
            std::cerr << "Error: invalid rate format => " << rateStr << '\n';
        }
    }

    file.close();
}

void BitcoinExchange::processFile() {
    std::ifstream file = openFile(_inputFile);
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) 
            continue;

        size_t sepPos = line.find(" | ");
        if (sepPos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << '\n';
            continue;
        }

        std::string date = line.substr(0, sepPos);
        std::string valueStr = line.substr(sepPos + 3);

        if (!parseDate(date)) {
            std::cerr << "Error: bad input => " << date << '\n';
            continue;
        }
        if (!parseValue(valueStr)) {
            std::cerr << "Error: invalid value => " << valueStr << '\n';
            continue;
        }

        try {
            float rate = findClosestRate(date);
            float value = std::stof(valueStr);
            float result = rate * value;

            std::cout << date << " => " << valueStr << " = " << result << '\n';
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    file.close();
}
