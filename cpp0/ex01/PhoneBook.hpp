#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

#include <iostream>
#include <iomanip>
#include <cctype>
#include <stdbool.h>
#include <limits>
#include <cstdlib> 
#include "Contact.hpp"

class PhoneBook {

private:

    Contact _contact[8];
    int _index;
    int _nbContact;

public:
    
    PhoneBook(void);
    ~PhoneBook(void);
    bool InputUser(void);
    void AddFunction(void);
    void SearchFunction(void);
    void PrintFunction(void);

};

#endif