#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog("Dog");
    const Animal* i = new Cat("Cat");
    const WrongAnimal* k = new WrongCat("WrongCat");
    std::cout << "type == [ " << meta->getType() << " ]" << std::endl;
    std::cout << "type == [ " << i->getType() << " ]" << std::endl;
    std::cout << "type == [ " <<  j->getType() << " ]" << std::endl;
    std::cout << "type == [ " << k->getType() << " ]" << std::endl;
    meta->makeSound(); //will output the default sound!
    i->makeSound(); //will output the Cat sound!
    j->makeSound(); //will output the Dog sound!
    k->makeSound(); //will output the default sound!

    return 0;
}