#include <iostream>
#include <cctype>
#include <set>

class Span {

    private:

        unsigned int _size;
        std::multiset<int> _array;

    public:

        Span();
        Span(unsigned int N);
        Span(const Span &src);
        ~Span();
        Span &operator=(const Span &src);
        void addNumber(int n);
        int longestSpan() const;
        int shortestSpan() const;

    class full : public std::exception {
    public:
        virtual const char *what() const throw() {
            return ("Already full\n");
        }
    };

    class infSize : public std::exception {
    public:
        virtual const char *what() const throw() {
            return ("Size too small\n");
        }
    };
};