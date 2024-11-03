#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("Default") {
    std::cout << "Default : AAnimal Constructor Called" << std::endl;
}

AAnimal::AAnimal(std::string value) : type(value) {
    std::cout << "AAnimal : " << this->getType() << " Constructor Called" << std::endl;
}

AAnimal::~AAnimal(void) {
    std::cout << "AAnimal : Destructor Called" << std::endl;
}

void   AAnimal::setType(std::string value) {
    this->type = value;
}

AAnimal&   AAnimal::operator=(const AAnimal& value) {
    this->type = value.getType();
    return (*this);
}

std::string   AAnimal::getType(void) const {
    return (this->type);
}

void AAnimal::makeSound (void) const {
	std::cout  << this->getType() << " : == MAKE SOUND == !" << std::endl;
}