#ifndef DOG_HPP
#define  DOG_HPP
#include "Animal.hpp"

class Dog: public Animal {
   
    public:
        
        Dog();
        Dog(Dog const &src);
        Dog(std::string value);
        Dog&   operator=(const Dog& value);
        ~Dog(void);
        virtual std::string   getType(void) const;
        virtual void makeSound (void) const;
};


#endif