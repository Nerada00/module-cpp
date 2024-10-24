#include "Zombie.hpp"

int main(void)
{
    Zombie *test = newZombie("abdmessa");
    test->announce();
    delete test;
    randomChump("moi");
}