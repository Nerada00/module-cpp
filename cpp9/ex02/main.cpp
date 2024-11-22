#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe [sequence of positive integers]\n";
        return 1;
    }

    try {
        PmergeMe sorter;
        sorter.loadInput(argv);
        sorter.sortAndMeasureTime();
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}
