#ifndef WRONG_CAT_HPP
#define  WRONG_CAT_HPP

#include "Animal.hpp"
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
    
    public:
        
        WrongCat(void);
        WrongCat(WrongCat const &src);
        WrongCat(std::string value);
        ~WrongCat(void);
        WrongCat&   operator=(const WrongCat& value);
        std::string   getType(void) const;
        void makeSound (void) const;
};

#endif