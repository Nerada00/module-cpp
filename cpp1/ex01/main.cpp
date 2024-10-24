#include "Zombie.hpp"

int main (void)
{
	int i;
	int test1 = 12;
	int test2 = 3;
	Zombie *zombie = zombieHorde(test1, "abdmessa");
	for (i = 0; i < test1; i++)
	{
		std::cout << "Zombie Number [" << i << "] ";
		zombie[i].announce();
	}
	std::cout << std::endl;
	delete [] zombie;
	std::cout << "Zombies horde is dead" << std::endl;
	zombie = zombieHorde(test2, "abdmessa");
	for (i = 0; i < test2; i++)
	{
		std::cout << "Zombie Number " << i << "] ";
		zombie[i].announce();
	}
	std::cout << std::endl;
	delete [] zombie;
	std::cout << "Zombies horde is dead" << std::endl;
	return (0);
}