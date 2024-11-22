#pragma once

#include <string>
#include <iostream>
#include <stack>
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
    double stringToDouble(const std::string &str); // Déclaration manquante ajoutée ici
};
