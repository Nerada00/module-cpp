#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->_hitPoint = 100;
    this->_energyPoint = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " << this->_name << " constructed" << std::endl;

}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->_name << " destructed" << std::endl;
}

ScavTrap &ScavTrap::operator=( ScavTrap const & value )
{
	if (this != &value)
	{
		this->_name = value._name;
		this->_hitPoint = value._hitPoint;
		this->_energyPoint = value._energyPoint;
		this->_attackDamage = value._attackDamage;
	}
	return *this;
}
void    ScavTrap::guardGate(void) {
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(std::string target) {
    if (this->quota() == true)
    {
        std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoint--;
    }
}
