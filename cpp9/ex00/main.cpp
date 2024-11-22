#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./btc [filename]\n";
        return (KO);
    }

    try {
        BitcoinExchange btc(argv[1]);
        btc.loadDataFile("data.csv");
        btc.processFile();
    }
    catch (const std::exception &e) 
    {
        std::cerr << e.what() << '\n';
        return (KO);
    }

    return (OK);
}
