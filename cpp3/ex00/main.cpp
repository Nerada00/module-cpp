#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap test("CLAPY");
    test.attack("cabouzir");
    test.takeDamage(5);
    test.attack("cyaid");
    test.beRepaired(5);
    test.takeDamage(10);
    test.attack("moi");

}