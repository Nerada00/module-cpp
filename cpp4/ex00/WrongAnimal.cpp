#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("Default") {
    std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string value) : type(value) {
    std::cout << "WrongAnimal " << this->getType() << " constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "WrongAnimal desstructor called" << std::endl;
}

void   WrongAnimal::setType(std::string value) {
    this->type = value;
}

WrongAnimal&   WrongAnimal::operator=(const WrongAnimal& value) {
    this->type = value.getType();
    return (*this);
}

std::string   WrongAnimal::getType(void) const {
    return (this->type);
}

void WrongAnimal::makeSound (void) const {
	std::cout  << this->getType() << " : == MAKE SOUND == !" << std::endl;
}