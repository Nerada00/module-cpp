#ifndef ANIMAL_HPP
#define  ANIMAL_HPP

#include <iostream>
#include <cctype>

class Animal {

protected:

    std::string type;

public:

    Animal();
    Animal(std::string type);
    virtual ~Animal();
    virtual void makeSound(void) const;
    virtual void   setType(std::string value);
    virtual std::string   getType() const;
    Animal&   operator=(const Animal& value);

};

#endif