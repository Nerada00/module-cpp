#include "Span.hpp"

Span::Span() {}
Span::Span(unsigned int N) : _size(N) {}
Span::Span(const Span &src) {*this = src;}
Span::~Span() {}

Span &Span::operator=(const Span &src) {
    if (this != &src)
	{
		_size = src._size;
		_array = src._array;
	}
	return (*this);
}

void Span::addNumber(int n) {
    if (_array.size() >= _size)
        throw full();
    _array.insert(n);
}

int Span::shortestSpan() const {
    if (_array.size() < 2)
        throw infSize();

    std::multiset<int>::iterator it = _array.begin();
    std::multiset<int>::iterator next = ++_array.begin();
    int minSpan = std::numeric_limits<int>::max();

    while (next != _array.end()) {
        int diff = *next - *it;
        if (diff < minSpan)
            minSpan = diff;
        ++it;
        ++next;
    }
    return (minSpan);
}

int Span::longestSpan() const {
    if (_array.size() < 2)
        throw std::logic_error("Not enough numbers to calculate a span.");
    
    return *std::prev(_array.end()) - *_array.begin();
}