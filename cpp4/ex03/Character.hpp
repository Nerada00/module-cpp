#pragma once

#include <iostream>
#include <cctype>
#include "ICharacter.hpp"

#define MAX 4

class AMateria;

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria *_inventory[4];
        AMateria *_ground[4];

    public:
        Character();
        Character(std::string name);
        Character(const Character &rhs);
        ~Character();

        Character   &operator=(const Character &rhs);
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};
