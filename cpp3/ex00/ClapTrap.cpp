#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
    std::cout << "Constructor called" << std::endl;
    std::cout << "ClapTrap " << this->_name << " is born"  << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
} 

ClapTrap&   ClapTrap::operator=(const ClapTrap& value) {
    this->_name = value._name;
    this->_hitPoint = value._hitPoint;
    this->_energyPoint = value._energyPoint;
    this->_attackDamage = value._attackDamage;
    return *this;
}

bool    ClapTrap::quota(void) {
    if (this->_energyPoint <= 0 || this->_hitPoint <= 0)
        return ((std::cout << "no energy point or hit point" << std::endl), false);
    return (true);
}

void ClapTrap::attack(const std::string& target) {
    if (this->quota() == true)
    {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoint--;
    }
}

void ClapTrap::setHitPoint(unsigned int value) {
    this->_hitPoint = value;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoint <= amount)
        {
            std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
            this->setHitPoint(0);
            return;
        }
        std::cout << "ClapTrap " << _name << " takes " << amount << " damage!" << std::endl;
        this->_hitPoint -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->quota() == true) {
        std::cout << "ClapTrap " << this->_name << " be repaired of " << amount << " hit point" << std::endl;
		this->_hitPoint += amount;
		this->_energyPoint--;
    }
}