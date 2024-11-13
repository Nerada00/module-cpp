#include "Animal.hpp"

Animal::Animal(void) : type("Default") {
    std::cout << "Default : Animal Constructor Called" << std::endl;
}

Animal::Animal(std::string value) : type(value) {
    std::cout << "Animal : " << this->getType() << " Constructor Called" << std::endl;
}

Animal::Animal(Animal const &src) {
    *this = src;
}

Animal::~Animal(void) {
    std::cout << "Animal : Destructor Called" << std::endl;
}

void   Animal::setType(std::string value) {
    this->type = value;
}

Animal&   Animal::operator=(const Animal& value) {
    this->type = value.getType();
    return (*this);
}

std::string   Animal::getType(void) const {
    return (this->type);
}

void Animal::makeSound (void) const {
	std::cout  << this->getType() << " : == MAKE SOUND == !" << std::endl;
}