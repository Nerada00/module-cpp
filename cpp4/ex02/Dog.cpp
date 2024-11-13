#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog") {
    std::cout << "Dog : Default Constructor Called" << std::endl;
    this->_brain = new Brain();

}

Dog::Dog(Dog const &src) {
    *this = src;
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
    *this->_brain = *value.getBrain();
    return (*this);
}

Brain   *Dog::getBrain(void) const {
    return (this->_brain);
}

std::string   Dog::getType(void) const {
    return (this->type);
}

void Dog::makeSound (void) const {
	std::cout  << this->getType() << " : Ouafff !" << std::endl;
}