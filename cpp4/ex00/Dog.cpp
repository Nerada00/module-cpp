#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
    std::cout << "Dog : Default Constructor Called" << std::endl; 
}

Dog::Dog(Dog const &src) {
    *this = src;
}

Dog::Dog( std::string value ) : Animal(value) {
    std::cout << "Dog : Constructor Called" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog : Destructor Called" << std::endl;
}

Dog&   Dog::operator=(const Dog& value) {
    this->type = value.getType();
    return (*this);
}

std::string   Dog::getType(void) const {
    return (this->type);
}

void Dog::makeSound (void) const {
	std::cout  << this->getType() << " : Ouafff !" << std::endl;
}