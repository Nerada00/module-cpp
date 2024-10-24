#include "Fixed.hpp"

Fixed::Fixed(void) {
    this->_entier = 0;
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed(const Fixed &value) {
    std::cout << "Copy constructor called" << std::endl;
    this->operator= (value);
    return;
}

Fixed::Fixed (const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->_entier = value << this->_bits;
}

Fixed::Fixed (const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->_entier = roundf(value * (1 << this->_bits));
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
    return;
}

Fixed	&Fixed::operator=(const Fixed& value) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_entier = value.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const {
    return  (this->_entier);
}

void Fixed::setRawBits( int const raw ) {
    this->_entier  = raw;
}

float 	Fixed::toFloat(void) const {
	return (static_cast<float>(this->_entier) / (1 << this->_bits));
}

int 	Fixed::toInt( void) const {
	return (this->_entier >> this->_bits);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &value) {
	out << value.toFloat();
	return (out);
}

// Les 6 opérateur de comparaison :

bool	Fixed::operator>(const Fixed &value) {
	return (this->_entier > value.getRawBits());
}

bool	Fixed::operator<(const Fixed &value) {
	return (this->_entier < value.getRawBits());
}

bool	Fixed::operator>=(const Fixed &value) {
	return (this->_entier >= value.getRawBits());
}

bool	Fixed::operator<=(const Fixed &value) {
	return (this->_entier <= value.getRawBits());
}

bool	Fixed::operator==(const Fixed &value) {
	return (this->_entier == value.getRawBits());
}

bool	Fixed::operator!=(const Fixed &value) {
	return (this->_entier != value.getRawBits());
}
// Les 4 opérateurs de arithmétiques :

Fixed	&Fixed::operator+(const Fixed &value) {
	this->_entier += value.getRawBits();
	return (*this);
}

Fixed	&Fixed::operator-(const Fixed &value) {
	this->_entier -= value.getRawBits();
	return (*this);
}

Fixed	&Fixed::operator*(const Fixed &value) {
    this->_entier = (this->_entier * value.getRawBits()) >> _bits;
    return (*this);
}

Fixed	&Fixed::operator/(const Fixed &value) {
	this->_entier =  (this->_entier << this->_bits) / value.getRawBits();
    return (*this);
}

// Les 4 opérateurs d’incrémentation et de décrémentation :

Fixed	&Fixed::operator++(void) {
	this->_entier++;
	return (*this);
}

Fixed	&Fixed::operator--(void) {
	this->_entier--;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed	Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

// les 4 fonctions membres publiques surchargées :

Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b){
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}
