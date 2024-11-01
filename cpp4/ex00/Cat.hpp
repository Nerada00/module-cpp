#ifndef CAT_HPP
#define  CAT_HPP

#include "Animal.hpp"

class Cat: public Animal {
    
    public:
        
        Cat&   operator=(const Cat& value);
        Cat(void);
        Cat(std::string value);
        ~Cat(void);
        virtual std::string   getType(void) const;
        virtual void makeSound (void) const;
};

#endif