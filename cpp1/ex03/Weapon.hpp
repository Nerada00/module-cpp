#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <cctype>

class Weapon {
	
private:
	std::string _type;

public:

	Weapon(std::string type);
	std::string &getType(void);
	void setType(std::string str);
};

#endif