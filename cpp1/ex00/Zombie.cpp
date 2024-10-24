#include "Zombie.hpp"

Zombie::Zombie(void) {
    std::cout << "Constructor called" << std::endl;
    return;
}

Zombie::~Zombie(void) {
    std::cout << "Destructor called" << std::endl;
    return;
}

std::string Zombie::setName(std::string value) {
    return (this->_name = value);
}

void Zombie::announce( void ) {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie( std::string name ) {
    Zombie *newZomb = new Zombie;
    newZomb->setName(name);
    return (newZomb);
}

void randomChump( std::string name ) {
    Zombie zombie;
    zombie.setName(name);
    zombie.announce();
}
