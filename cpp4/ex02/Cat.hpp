#ifndef CAT_HPP
#define  CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal {
    
    private:

        Brain *_brain;

    public:
        
        Cat&   operator=(const Cat& value);
        Cat(void);
        Cat(std::string value);
        ~Cat(void);
        Brain   *getBrain(void) const;
        virtual std::string   getType(void) const;
        virtual void makeSound (void) const;
};

#endif