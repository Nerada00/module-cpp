#include "Contact.hpp"

Contact::Contact(void) {
    //std::cout << "Constructor Contact called" << std::endl;
    return;
}

Contact::~Contact(void) {
   //std::cout << "Destructor called" << std::endl;
    return;
}

// Getters

std::string Contact::GetFirstName(void) const {
    return (this->_firstName);
}

std::string Contact::GetLastName(void) const {
    return (this->_lastName);
}

std::string Contact::GetNickName(void) const {
    return (this->_nickName);
}

std::string Contact::GetPhoneNumber(void) const {
    return (this->_phoneNumber);
}

std::string Contact::GetDarkestSecret(void) const {
    return (this->_darkestSecret);
}

int Contact::GetIndexContact(void) const {
    return (this->_indexContacts);
}

// Setters

void Contact::SetIndexContact(int value) {
    _indexContacts = value;
}

void Contact::SetFirstName(std::string value) {

    while (1)
    {
        bool alpha = true;
        if (value.empty())
            alpha = false;
        for (unsigned int i = 0; i < value.length(); i++)
        {
            if (!isalpha(value[i]))
                alpha = false;
        }
        if (alpha == true)
        {
            _firstName = value;
            break;
        }
        else
        {
            std::cout << "Wrong input try again" << std::endl;
            getline(std::cin, value);
            continue;
        }
    }
}

void Contact::SetLastName(std::string value) {

    while (1)
    {
        bool alpha = true;
        if (value.empty())
            alpha = false;
        for (unsigned int i = 0; i < value.length(); i++)
        {
            if (!isalpha(value[i]))
                alpha = false;
        }
        if (alpha == true)
        {
            _lastName = value;
            break;
        }
        else
        {
            std::cout << "Wrong input try again" << std::endl;
            getline(std::cin, value);
            continue;
        }
    }
    
}

void Contact::SetNickName(std::string value) {
    while (1)
    {
        if (!value.empty())
        {
            _nickName = value;
            break;
        }
        else{
            std::cout << "Wrong input try again" << std::endl;
        }
        getline(std::cin, value);
    }
}

void Contact::SetPhoneNumber(std::string value) {
    while (1)
    {
        bool num = true;
        if (value.empty())
            num = false;
        for (unsigned int i = 0; i < value.length(); i++)
        {
            if (!isnumber(value[i]))
                num = false;
        }
        if (num == true)
        {
            _phoneNumber = value;
            break;
        }
        else
        {
            std::cout << "Wrong input try again" << std::endl;
            getline(std::cin, value);
            continue;
        }
    }
}

void Contact::SetDarkestSecret(std::string value) {
    while (1)
    {
        if (!value.empty())
        {
            _darkestSecret = value;
            break;
        }
        else{
            std::cout << "Wrong input try again" << std::endl;
        }
        getline(std::cin, value);
    }
}
