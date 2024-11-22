#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./RPN \"expression\"\n";
        return 1;
    }

    RPN calculator;

    try {
        double result = calculator.evaluate(argv[1]);
        std::cout << "Result: " << result << '\n';
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}
