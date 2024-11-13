#ifndef WRONG_ANIMAL_HPP
#define  WRONG_ANIMAL_HPP

#include <iostream>
#include <cctype>

class WrongAnimal {

protected:

    std::string type;

public:

    WrongAnimal();
    WrongAnimal(std::string type);
    WrongAnimal(WrongAnimal const &src);
    ~WrongAnimal();
    void makeSound(void) const;
    void   setType(std::string value);
    std::string   getType() const;
    WrongAnimal&   operator=(const WrongAnimal& value);

};

#endif