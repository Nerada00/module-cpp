#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <cctype>

class Contact {

private:

        std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
        int _indexContacts;

public:

    Contact(void);
    ~Contact(void);
    int GetIndexContact(void) const;
    std::string GetFirstName(void) const;
    std::string GetLastName(void) const;
    std::string GetNickName(void) const;
    std::string GetPhoneNumber(void) const;
    std::string GetDarkestSecret(void) const;
    void SetIndexContact(int value);
    void SetFirstName(std::string value);
    void SetLastName(std::string value);
    void SetNickName(std::string value);
    void SetPhoneNumber(std::string value);
    void SetDarkestSecret(std::string value);
};

#endif