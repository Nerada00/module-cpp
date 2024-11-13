#ifndef CAT_HPP
#define  CAT_HPP

#include "Animal.hpp"

class Cat: public Animal {
    
    public:
        
        Cat();
        Cat(Cat const &src);
        Cat(std::string value);
        ~Cat(void);
        Cat&   operator=(const Cat& value);
        virtual std::string   getType(void) const;
        virtual void makeSound (void) const;
};

#endif