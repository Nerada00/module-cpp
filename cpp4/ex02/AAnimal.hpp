#ifndef AANIMAL_HPP
#define  AANIMAL_HPP

#include <iostream>
#include <cctype>

class AAnimal {

protected:

    std::string type;

public:

    AAnimal();
    AAnimal(AAnimal const &src);
    AAnimal(std::string type);
    virtual ~AAnimal();
    virtual void makeSound(void) const = 0;
    virtual void   setType(std::string value);
    virtual std::string   getType() const;
    AAnimal&   operator=(const AAnimal& value);

};

#endif