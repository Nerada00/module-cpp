#pragma once


#include <iostream>
#include <cctype>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Ice : public AMateria {

    public:
        Ice();
        Ice(const Ice &rhs);
        ~Ice();
        void use(ICharacter& target);
        AMateria *clone() const;
        Ice &operator=(const Ice &src);

};
