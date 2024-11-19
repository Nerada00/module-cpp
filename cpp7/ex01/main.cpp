#include "Iter.hpp"

int main()
{
    int tab[] = {1, 2, 3};
    float tab2[] = {1.1f, 2.1f, 3.1f};
    std::string tab3[] = {"cyaid", "cabouzir", "abdmessa"};
    std::cout << "====Int test====\n";
    iter(tab, 3, printer);
    std::cout << "\n====Float test====\n";
    iter(tab2, 3, printer);
    std::cout << "\n====String test====\n";
    iter(tab3, 3, printer);
}