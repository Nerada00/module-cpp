#include "MutantStack.hpp"
#define GREEN "\033[32m"
#define WHITE "\033[0m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"


int main() {
    
    std::cout << GREEN "\n================ STACK TEST ================\n\n" << WHITE;
    {
        MutantStack<int> mstack;

        mstack.push(21);
        mstack.push(42);

        std::cout << std::setw(21) << BLUE "Iterator :" << WHITE "\n";
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++) {
            std::cout << std::setw(24) << CYAN << *it << '\n';
        }

        std::cout << std::setw(20) << BLUE "Const Iterator :" << WHITE "\n";;
        for (MutantStack<int>::const_iterator it = mstack.begin(); it != mstack.end(); it++) {
            std::cout << std::setw(24) << CYAN << *it << '\n';
        }
    }

    {
        std::cout << GREEN "\n================ LIST TEST =================\n\n" << WHITE;
        std::list<int> mstack;

        mstack.push_back(21);
        mstack.push_back(42);

        std::cout << std::setw(21) << BLUE "Iterator :" << WHITE"\n";
        for (std::list<int>::iterator it = mstack.begin(); it != mstack.end(); it++) {
            std::cout << std::setw(24) << CYAN << *it << '\n';
        }

        std::cout << std::setw(20) << BLUE "Const Iterator :" << WHITE "\n";;
        for (std::list<int>::const_iterator it = mstack.begin(); it != mstack.end(); it++) {
            std::cout << std::setw(24) << CYAN << *it << '\n';
        }
        std::cout << GREEN "\n============================================\n" << WHITE;

        return (0);
    }
}


