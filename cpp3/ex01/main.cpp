#include "ScavTrap.hpp"

int main(void)
{
    std::cout << std::endl << "==========================================" << std::endl << std::endl;
    ClapTrap test("CLAPY"); 
    ScavTrap test2("SCAVY");
    std::cout << std::endl << "==========================================" << std::endl << std::endl;
    test.attack("cabouzir");
    test.takeDamage(10);
    test.attack("cabouzir");
    std::cout << std::endl << "==========================================" << std::endl << std::endl;
    test2.attack("cyaid");
    test2.guardGate();
    test2.takeDamage(1000);
    test2.attack("cyaid");
    std::cout << std::endl << "==========================================" << std::endl << std::endl;
}