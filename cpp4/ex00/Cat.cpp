#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
    std::cout << "Cat : Default Constructor Called"  << std::endl; 
}

Cat::Cat(Cat const &src) {
    *this = src;
}

Cat::Cat( std::string value ) : Animal(value) {
    std::cout << "Cat : Constructor Called"  << std::endl;
}

Cat::~Cat(void) {
    std::cout << "Cat : Destructor Called"  << std::endl; 
}

Cat&   Cat::operator=(const Cat& value) {
    this->type = value.getType();
    return (*this);
}

std::string   Cat::getType(void) const {
    return (this->type);
}

void Cat::makeSound (void) const {
	std::cout  << this->getType() << " : Miiiaaouuuuuuuuu !" << std::endl;
}