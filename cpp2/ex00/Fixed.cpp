#include "Fixed.hpp"

Fixed::Fixed(void) {
    this->_entier = 0;
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed(const Fixed &value) {
    this->_entier = value._entier;
    std::cout << "Copy constructor called" << std::endl;
    return;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
    return;
}

Fixed	&Fixed::operator=(const Fixed& value)
{
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
