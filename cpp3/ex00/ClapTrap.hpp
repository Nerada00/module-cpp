#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <cctype>
#include <stdbool.h>

class ClapTrap {

private: 

    std::string _name;
    unsigned int _hitPoint;
    unsigned int _energyPoint;
    unsigned int _attackDamage;

public:

    ClapTrap(std::string name);
    ~ClapTrap();
    ClapTrap&   operator=(const ClapTrap& value);
    bool quota(void);
    void setHitPoint(unsigned int value);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};
#endif