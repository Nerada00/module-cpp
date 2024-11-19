#pragma once

#include <iostream>
#include <exception>
#include <iomanip>

#define GREEN "\033[32m"
#define WHITE "\033[0m"

template <typename T>
class Array {

    private:

        unsigned int _size;
        T *_array;

    public:

        Array(): _size(0), _array(new T[_size]) {};

        Array(unsigned int size): _size(size), _array(new T[_size]) {
            for (unsigned int i = 0; i < this->_size; i++)
                this->_array[i] = T();
        };

        Array(Array const & src) : _size(src._size), _array(new T[_size]) {
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = src._array[i];
		}

		~Array(void) {delete [] this->_array;}

        T &operator[](unsigned int index) {
            if (index >= this->_size)
                throw (OutOfBoundException());
            return this->_array[index];
        }

        const T& operator[](unsigned int index) const {
            if (index >= this->_size)
                throw (OutOfBoundException());
            return this->_array[index];
        }

        Array &operator=(Array const &rhs) {
			if (this != &rhs)
			{
				delete [] this->_array;
				this->_size = rhs._size;
				this->_array = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++)
					this->_array[i] = rhs._array[i];
			}
			return (*this);
        }

        unsigned int size() const {
            return (this->_size);
        }

        class OutOfBoundException : public std::exception {
            public:
                virtual const char *what() const throw() {
                    return ("Array is OOB\n");
                }
        };
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &arr)
{
    out << GREEN "\n-------------------------------------" << "\n";
    out << "|                TEST               |" << "\n";
    out << "-------------------------------------" << WHITE << "\n";
    out << "|";
    for (unsigned int i = 0; i < arr.size(); ++i) {
        out << std::setw(11) << arr[i] << "|";
    }
    out << "\n-------------------------------------\n\n";
    return (out);
}