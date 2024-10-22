#ifndef FIXED_H
#define FIXED_H

#include <cctype>
#include <iostream>

class Fixed {

private:

    int _entier;
    const static int _bits = 8;

public:

    Fixed();
    Fixed(const Fixed &value);
    ~Fixed();
    Fixed &operator=(const Fixed &value);
    int getRawBits(void) const;
    void setRawBits(int const raw);

};

#endif