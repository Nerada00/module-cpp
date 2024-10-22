#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook   instance;
    std::cout << "Welcome to PhoneBook" << std::endl;
    while (1)
    {
        if (instance.InputUser() == false)
            break;
    }
    return (0);
}