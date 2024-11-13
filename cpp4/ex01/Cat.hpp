#ifndef CAT_HPP
#define  CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
    
    private:

        Brain *_brain;

    public:
        
        Cat&   operator=(const Cat& value);
        Cat(void);
        Cat(std::string value);
        Cat(Cat const &src);
        ~Cat(void);
        Brain   *getBrain(void) const;
        virtual std::string   getType(void) const;
        virtual void makeSound (void) const;
};

#endif