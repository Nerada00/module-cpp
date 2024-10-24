#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL) {}

void HumanB::attack(void) {
    if (_weapon == NULL)
        return;
    std::cout << this->_name << "attacks with their" << _weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}
