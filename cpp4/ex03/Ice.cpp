#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice() : AMateria("ice") {
    // std::cout << "Constructor Ice Called" << std::endl;
}

Ice::Ice(const Ice &rhs) : AMateria("ice") {
    (void)rhs;
}

Ice::~Ice() {
    // std::cout << "Destructor Ice Called" << std::endl;
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria *Ice::clone() const
{
	return (new Ice());
}

Ice &Ice::operator=(const Ice &src)
{
	(void)src;
	return (*this);
}