#ifndef DOG_HPP
#define  DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal {
    
    private:
        
        Brain *_brain;

    public:
        
        Dog(void);
        Dog(Dog const &src);
        Dog(std::string value);
        Dog&   operator=(const Dog& value);
        ~Dog(void);
        Brain   *getBrain(void) const;
        virtual std::string   getType(void) const;
        virtual void makeSound (void) const;
};


#endif