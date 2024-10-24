#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
	//std::cout << "Contructor" << std::endl;
}
std::string &Weapon::getType(void) {
	return (this->_type);
}

void Weapon::setType(std::string str) {
	this->_type = str;
}