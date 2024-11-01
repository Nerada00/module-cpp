#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {

private:
    ScavTrap();

public:
    
    ScavTrap(std::string name);
    ~ScavTrap();
    ScavTrap &operator=(ScavTrap const & value);
    void attack(std::string target);
    void guardGate();

};

#endif