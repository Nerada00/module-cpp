#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "AAnimal.hpp"

int main()
{
    // const AAnimal* i = new AAnimal();
    const AAnimal* j = new Cat();

    // i->makeSound();
    j->makeSound();

return 0;
}