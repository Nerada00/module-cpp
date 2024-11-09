#include "AMateria.hpp"

AMateria::AMateria() {
    // std::cout << "AMateria Default Constructor Called" << std::endl;
}
AMateria::AMateria(std::string const & type) : _type(type) {
    // std::cout << "AMateria Constructor Called" << std::endl;
}
AMateria::~AMateria() {
    // std::cout << "AMateria Desstructor Called" << std::endl;
}

std::string const &AMateria::getType() const {
    return (this->_type);
}

void AMateria::use(ICharacter& target) {
    std::cout << "AMateria use is called toward" << target.getName() << "but action not define" << std::endl;
}