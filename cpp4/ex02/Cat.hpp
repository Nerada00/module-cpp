#ifndef CAT_HPP
#define  CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal {
    
    private:

        Brain *_brain;

    public:
        
        Cat();
        Cat(Cat const &src);
        Cat(std::string value);
        ~Cat(void);
        Cat&   operator=(const Cat& value);
        Brain   *getBrain(void) const;
        virtual std::string   getType(void) const;
        virtual void makeSound (void) const;
};

#endif