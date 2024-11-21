#include "Span.hpp"

int main() {

    std::cout << "\n===================== TEST =====================\n\n";

    try {
        Span sp(2);
        sp.addNumber(42);
        sp.addNumber(42);
        sp.addNumber(42);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
    std::cout << "\n===================== TEST =====================\n\n";

    try {
        Span sp(1);
        sp.addNumber(42);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
    std::cout << "\n===================== TEST =====================\n\n";
    try {
        Span sp(10000);

        for (int i = 1; i < 10001; ++i) {
            sp.addNumber(i); 
        }
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }

  


    return (0);
}
