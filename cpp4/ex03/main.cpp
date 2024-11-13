#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"


int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");
    AMateria* tmp;

    for (int i = 0; i < 2; i++)
    {  
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
    }

    me->unequip(0);
 
    for (int i = 0; i < 4; i++)
        me->use(i, *bob);

    delete bob;
    delete me;
    delete src;
    return 0;
}
