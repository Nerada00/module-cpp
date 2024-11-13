#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
    std::cout << "WrongCat : Default Constructor Called"  << std::endl; 
}

WrongCat::WrongCat(WrongCat const &src) {
    *this = src;
}

WrongCat::WrongCat( std::string value ) : WrongAnimal(value) {
    std::cout << "WrongCat : Constructor Called"  << std::endl;
}

WrongCat::~WrongCat(void) {
    std::cout << "WrongCat : Destructor Called"  << std::endl; 
}

WrongCat&   WrongCat::operator=(const WrongCat& value) {
    this->type = value.getType();
    return (*this);
}

std::string   WrongCat::getType(void) const {
    return (this->type);
}

void WrongCat::makeSound (void) const {
	std::cout  << this->getType() << " : Miiiaaouuuuuuuuu !" << std::endl;
}