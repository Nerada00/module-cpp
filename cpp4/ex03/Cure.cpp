#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
    // std::cout << "Constructor Cure Called" << std::endl;
}

Cure::Cure(const Cure &rhs) : AMateria("cure") {
    (void)rhs;
}

Cure::~Cure() {
    // std::cout << "Destructor Cure Called" << std::endl;
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals "<< target.getName() << "’s wounds *" << std::endl;
}

AMateria *Cure::clone() const
{
	return (new Cure());
}

Cure &Cure::operator=(const Cure &src)
{
	(void)src;
	return (*this);
}