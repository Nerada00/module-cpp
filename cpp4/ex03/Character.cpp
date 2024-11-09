#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _name("Default") {
    // std::cout << "Character Default constructor called" << std::endl;
    	for (int i = 0; i < MAX; i++)
    		_inventory[i] = NULL;
}

Character::Character(std::string name): _name(name) {
    // std::cout << "Character constructor called" << std::endl;
       	for (int i = 0; i < MAX; i++)
       		_inventory[i] = NULL;
}

Character::Character(const Character& rhs) {
    *this = rhs;
}

Character & Character::operator=(Character const & rhs) {
    if (this != &rhs) {
        _name = rhs._name;
        
        for (int i = 0; i < 4; ++i) 
        {
            delete _inventory[i];  
            if (rhs._inventory[i] != nullptr) 
                _inventory[i] = rhs._inventory[i]->clone();
            else
                _inventory[i] = nullptr;
        }
    }
    return *this;
}

Character::~Character() {
    // std::cout << "Character Destructor called" << std::endl;
    for (int i = 0; i < MAX; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
}

std::string const & Character::getName() const {
    return (this->_name);
}

void Character::equip(AMateria* m) {
    if (!m)
        return;
    for (int i = 0; i < MAX; i++)
    {
        if (this->_inventory[i] == nullptr)
        {
            this->_inventory[i] = m;
            // std::cout << "Equipped " << m->getType() << " in slot " << i << std::endl;
            break;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < MAX)
        this->_inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter &target) {
        if (idx >= 0 && idx < 4 && this->_inventory[idx])
            this->_inventory[idx]->use(target);
} 
