#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <cctype>

class Zombie {

private:

    std::string _name;

public:
    Zombie(void);
    ~Zombie(void);
    std::string setName(std::string value);
    void announce( void );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );
Zombie* zombieHorde( int N, std::string name );

#endif