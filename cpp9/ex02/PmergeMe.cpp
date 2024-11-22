#include "PmergeMe.hpp"
#include <algorithm>

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &src) {
    this->_vectorContainer = src._vectorContainer;
    this->_listContainer = src._listContainer;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
    if (this != &rhs) {
        this->_vectorContainer = rhs._vectorContainer;
        this->_listContainer = rhs._listContainer;
    }
    return (*this);
}

std::vector<int> PmergeMe::JacobsthalCeBeauGosse(int size) {
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    int n = 2;
    while (true) {
        int next = jacobsthal[n - 1] + 2 * jacobsthal[n - 2];
        if (next >= size)
            break;
        jacobsthal.push_back(next);
        n++;
    }
    return jacobsthal;
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& arr) {

    if (arr.size() <= 1)
        return;

    std::vector<int> left(arr.begin(), arr.begin() + arr.size() / 2);
    std::vector<int> right(arr.begin() + arr.size() / 2, arr.end());

    mergeInsertSortVector(left);
    mergeInsertSortVector(right);

    std::vector<int> merged;
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(merged));

    std::vector<int> jacobsthal = JacobsthalCeBeauGosse(merged.size());

    for (size_t i = 0; i < jacobsthal.size(); ++i) {
        if (jacobsthal[i] < (int)merged.size()) {
            arr[i] = merged[jacobsthal[i]];
        }
    }
}

void PmergeMe::mergeInsertSortList(std::list<int>& lst) {

    if (lst.size() <= 1)
        return;

    std::list<int> left, right;
    size_t halfSize = lst.size() / 2;
    std::list<int>::iterator it = lst.begin();

    for (size_t i = 0; i < halfSize; ++i, ++it) left.push_back(*it);
    for (; it != lst.end(); ++it) right.push_back(*it);

    mergeInsertSortList(left);
    mergeInsertSortList(right);

    lst.clear();
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(lst));
    std::vector<int> jacobsthal = JacobsthalCeBeauGosse(lst.size());
    it = lst.begin();
    size_t index = 0;
    
    for (size_t i = 0; i < jacobsthal.size(); ++i) {
        if (jacobsthal[i] < (int)lst.size()) {
            std::advance(it, jacobsthal[i] - index);
            index = jacobsthal[i];
        }
    }
}

void PmergeMe::sortAndMeasureTime() {
    struct timeval start, end;

    std::cout << "Before: ";
    for (size_t i = 0; i < _vectorContainer.size(); i++)
        std::cout << _vectorContainer[i] << " ";
    std::cout << std::endl;

    gettimeofday(&start, NULL);
    mergeInsertSortVector(_vectorContainer);
    gettimeofday(&end, NULL);

    long vectorTime = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);

    std::cout << "After: ";
    for (size_t i = 0; i < _vectorContainer.size(); i++)
        std::cout << _vectorContainer[i] << " ";
    std::cout << std::endl;

    gettimeofday(&start, NULL);
    mergeInsertSortList(_listContainer);
    gettimeofday(&end, NULL);

    long listTime = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    std::cout << "Time to process a range of " << _vectorContainer.size()
              << " elements with std::vector: " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _listContainer.size()
              << " elements with std::list: " << listTime << " us" << std::endl;
}

void PmergeMe::loadInput(char **argv) {
    for (int i = 1; argv[i]; i++) {
        int number = std::atoi(argv[i]);
        if (number < 0)
            throw std::invalid_argument("Error: Negative number detected.");
        _vectorContainer.push_back(number);
        _listContainer.push_back(number);
    }
}