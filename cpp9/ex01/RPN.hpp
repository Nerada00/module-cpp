#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>

class RPN {
    public:
        RPN();
        ~RPN();
        double evaluate(const std::string &expression);

    private:
        bool isOperator(const std::string &token);
        bool isNumber(const std::string &token);
        double applyOperator(const std::string &op, double operand1, double operand2);
};
