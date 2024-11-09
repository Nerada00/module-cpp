#pragma once


#include <iostream>
#include <cctype>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Cure : public AMateria{

    public:
        Cure();
        Cure(const Cure &src);
        ~Cure();
        void use(ICharacter& target);
        AMateria *clone() const;
        Cure &operator=(const Cure &src);


};

