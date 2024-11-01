#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->_hitPoint = 100;
    this->_energyPoint = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap " << this->_name << " constructed" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->_name << " destructed" << std::endl;
}


void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->_name << " do a high fives" << std::endl;
}
