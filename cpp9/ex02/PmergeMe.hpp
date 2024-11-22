#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <sys/time.h>

class PmergeMe {
private:
    std::vector<int> _vectorContainer;
    std::list<int> _listContainer;

    void mergeInsertSortVector(std::vector<int> &arr);
    void mergeInsertSortList(std::list<int> &lst);
    std::vector<int> JacobsthalCeBeauGosse(int size);

public:
    PmergeMe();
    PmergeMe(PmergeMe const &src);
    ~PmergeMe();
    PmergeMe &operator=(PmergeMe const &rhs);

    void loadInput(char **argv);
    void sortAndMeasureTime();
};
