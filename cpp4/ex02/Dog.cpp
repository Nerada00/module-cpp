#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog") {
    std::cout << "Dog : Default Constructor Called" << std::endl;
    this->_brain = new Brain();

}

Dog::Dog( std::string value ) : AAnimal(value) {
    std::cout << "Dog : Constructor Called" << std::endl;
    this->_brain = new Brain();

}

Dog::~Dog() {
    std::cout << "Dog : Destructor Called" << std::endl;
    delete this->_brain;
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