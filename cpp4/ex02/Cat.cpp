#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat") {
    std::cout << "Cat : Default Constructor Called"  << std::endl; 
    this->_brain = new Brain();
}

Cat::Cat( std::string value ) : AAnimal(value) {
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

Brain   *Cat::getBrain(void) const {
    return (this->_brain);
}

std::string   Cat::getType(void) const {
    return (this->type);
}

void Cat::makeSound (void) const {
	std::cout  << this->getType() << " : Miiiaaouuuuuuuuu !" << std::endl;
}