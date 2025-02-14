#ifndef DOG_HPP
#define  DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
    
    private:
        
        Brain *_brain;

    public:
        
        Dog&   operator=(const Dog& value);
        Dog(void);
        Dog(std::string value);
        Dog(Dog const &src);
        ~Dog(void);
        Brain   *getBrain(void) const;
        virtual std::string   getType(void) const;
        virtual void makeSound (void) const;
};


#endif