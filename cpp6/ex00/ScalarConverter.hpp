#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype> 
#include <limits>
#include <cmath>
#include <iomanip>

class ScalarConverter {

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &);
        ScalarConverter &operator=(const ScalarConverter &);
        static bool isChar(const std::string &literal);
        static bool isInt(const std::string &literal);
        static bool isFloat(const std::string &literal);
        static bool isDouble(const std::string &literal);
        static bool isSpecialLiteral(const std::string &literal);

    public:

        static void convert(const std::string &literal);
};
