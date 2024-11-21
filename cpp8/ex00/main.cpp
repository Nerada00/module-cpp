#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    try {
        std::list<int> nb;
        nb.push_back(11);
        nb.push_back(22);
        nb.push_back(32);
        nb.push_back(2);
        easyfind(nb, 0);
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }

    try {
        std::vector<int> nb;
        nb.push_back(9);
        nb.push_back(8);
        nb.push_back(7);
        nb.push_back(34);
        easyfind(nb, 34);
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
}