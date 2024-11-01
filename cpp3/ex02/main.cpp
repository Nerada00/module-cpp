#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    std::cout << std::endl << "==========================================" << std::endl << std::endl;
    FragTrap test("FRAGY"); 
    ScavTrap test2("SCAVY");
    std::cout << std::endl << "==========================================" << std::endl << std::endl;
    test.attack("cabouzir");
    test.takeDamage(100);
    test.attack("cabouzir");
    test.attack("mamoudou");
    test.attack("ayiiii");
    std::cout << std::endl << "==========================================" << std::endl << std::endl;
    test2.attack("cyaid");
    test2.guardGate();
    test2.takeDamage(1000);
    test2.attack("cyaid");
    std::cout << std::endl << "==========================================" << std::endl << std::endl;
}