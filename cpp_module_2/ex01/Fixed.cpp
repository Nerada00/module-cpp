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

float 	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_entier) / (1 << this->_bits));
}

int 	Fixed::toInt( void) const
{
	return (this->_entier >> this->_bits);
}

std::ostream	&operator<<( std::ostream &out, const Fixed &value )
{
	out << value.toFloat();
	return (out);
}