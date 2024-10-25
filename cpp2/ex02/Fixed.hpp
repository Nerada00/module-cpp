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
    Fixed &operator=(const Fixed &fix);
    Fixed &operator+(const Fixed &rhs);
    Fixed &operator-(const Fixed &rhs);
    Fixed &operator*(const Fixed &rhs);
    Fixed &operator/(const Fixed &rhs);
	bool	operator>(const Fixed &fix);
	bool	operator<(const Fixed &fix);
	bool	operator>=(const Fixed &fix);
	bool	operator<=(const Fixed &fix);
	bool	operator==(const Fixed &fix);
	bool	operator!=(const Fixed &fix);
	Fixed	&operator++(void);
	Fixed	&operator--(void);
	Fixed	operator++(int);
	Fixed	operator--(int);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float 	toFloat( void ) const;
    int 	toInt( void ) const;

    static Fixed	&min(Fixed &a, Fixed &b);
	static Fixed	&max(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);

};

std::ostream	&operator<<( std::ostream &out, const Fixed &value);

#endif