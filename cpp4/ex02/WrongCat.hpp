#ifndef WRONG_CAT_HPP
#define  WRONG_CAT_HPP

#include "AAnimal.hpp"
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
    
    public:
        
        WrongCat&   operator=(const WrongCat& value);
        WrongCat(void);
        WrongCat(WrongCat const &src);
        WrongCat(std::string value);
        ~WrongCat(void);
        std::string   getType(void) const;
        void makeSound (void) const;
};

#endif