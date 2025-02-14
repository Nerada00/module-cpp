#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <cctype> // Pour isdigit
#include <stack> // Pour std::stack

RPN::RPN() {}
RPN::~RPN() {}

bool RPN::isOperator(const std::string &token) {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(const std::string &token) {
    for (size_t i = 0; i < token.size(); i++) {
        if (!isdigit(token[i]))
            return false;
    }
    return !token.empty();
}

double RPN::applyOperator(const std::string &op, double operand1, double operand2) {
    if (op == "+") return operand1 + operand2;
    if (op == "-") return operand1 - operand2;
    if (op == "*") return operand1 * operand2;
    if (op == "/") {
        if (operand2 == 0)
            throw std::runtime_error("Error: Division by zero.");
        return operand1 / operand2;
    }
    throw std::runtime_error("Error: Unknown operator.");
}

double RPN::stringToDouble(const std::string &str) {
    std::istringstream iss(str);
    double value;
    if (!(iss >> value)) {
        throw std::runtime_error("Error: invalid number format.");
    }
    return value;
}


double RPN::evaluate(const std::string &expression) {
    std::stack<double> stack;
    std::istringstream tokens(expression);
    std::string token;

    while (tokens >> token) {
        if (isNumber(token)) {
            stack.push(stringToDouble(token)); // Utilise stringToDouble
        } else if (isOperator(token)) {
            if (stack.size() < 2)
                throw std::runtime_error("Error: insufficient operands.");
            
            double operand2 = stack.top(); stack.pop();
            double operand1 = stack.top(); stack.pop();
            double result = applyOperator(token, operand1, operand2);
            stack.push(result);
        } else {
            throw std::runtime_error("Error: invalid token.");
        }
    }

    if (stack.size() != 1)
        throw std::runtime_error("Error: invalid RPN expression.");
    
    return stack.top();
}
