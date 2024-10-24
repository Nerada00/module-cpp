#ifndef FIXED_H
#define FIXED_H

#include <cctype>
#include <iostream>
#include <cmath>

class Fixed {

private:

    int _entier;
    const static int _bits = 8;

public:

    Fixed();
    Fixed(const Fixed &value);
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed();

    Fixed &operator=(const Fixed &value);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float 	toFloat( void ) const;
    int 	toInt( void ) const;


};

std::ostream	&operator<<( std::ostream &out, const Fixed &fix );

#endif