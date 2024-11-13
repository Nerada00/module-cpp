#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
    std::cout << "Cat : Default Constructor Called"  << std::endl; 
    this->_brain = new Brain();
}

Cat::Cat( std::string value ) : Animal(value) {
    std::cout << "Cat : Constructor Called"  << std::endl;
    this->_brain = new Brain();

}

Cat::Cat(Cat const &src) {
    *this = src;
}

Cat::~Cat(void) {
    std::cout << "Cat : Destructor Called"  << std::endl; 
    delete this->_brain;
}

Cat&   Cat::operator=(const Cat& value) {
    this->type = value.getType();
    *this->_brain = *value.getBrain();
    return (*this);
}

std::string   Cat::getType(void) const {
    return (this->type);
}

Brain   *Cat::getBrain(void) const {
    return (this->_brain);
}

void Cat::makeSound (void) const {
	std::cout  << this->getType() << " : Miiiaaouuuuuuuuu !" << std::endl;
}