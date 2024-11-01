#ifndef WRONG_CAT_HPP
#define  WRONG_CAT_HPP

#include "Animal.hpp"
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
    
    public:
        
        WrongCat&   operator=(const WrongCat& value);
        WrongCat(void);
        WrongCat(std::string value);
        ~WrongCat(void);
        std::string   getType(void) const;
        void makeSound (void) const;
};

#endif