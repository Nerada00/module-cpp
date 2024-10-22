#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void): _index(0), _nbContact(0){
   // std::cout << "Constructor PhoneBook called" << std::endl;
    return;
}

PhoneBook::~PhoneBook(void) {
    // std::cout << "Destructor called" << std::endl;
    return;
}

void PhoneBook::SearchFunction(void) {
    if (_nbContact == 0){

    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "|                 No contact               |" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    return (void());
    }
    std::cout << "--------------------------------------------" << std::endl;
	std::cout << "    Index |First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
    for (int i = 0; i < _nbContact; i++)
    {
        std::cout << std::setw(10) << _contact[i].GetIndexContact() << "|";
        if (_contact[i].GetFirstName().length() > 10)
            std::cout << _contact[i].GetFirstName().substr(0, 9) << ".|";
        else
            std::cout << std::setw(10) << _contact[i].GetFirstName() << "|";

        if (_contact[i].GetLastName().length() > 10)
            std::cout << _contact[i].GetLastName().substr(0, 9) << ".|";
        else
            std::cout << std::setw(10) << _contact[i].GetLastName() << "|";

        if (_contact[i].GetNickName().length() > 10)
            std::cout << _contact[i].GetNickName().substr(0, 9) << ".|" << std::endl;
        else
            std::cout << std::setw(10) << _contact[i].GetNickName() << "|" << std::endl;
    }
    std::cout << "--------------------------------------------" << std::endl;

    PrintFunction();
}

void PhoneBook::PrintFunction(void) {
    std::string value;

    std::cout << "Enter an index: ";
    
    while (true) 
    {
        std::cin >> value;
        try {
            int index = std::stoi(value); 
            if (index > 0 && index <= _nbContact)
            {
                std::cout << "First Name: " << _contact[index - 1].GetFirstName() << std::endl; 
                std::cout << "Last Name: " << _contact[index - 1].GetLastName() << std::endl;
                std::cout << "Nickname: " << _contact[index - 1].GetNickName() << std::endl;
                std::cout << "Phone Number: " << _contact[index - 1].GetPhoneNumber() << std::endl;
                std::cout << "Darkest Secret: " << _contact[index - 1].GetDarkestSecret() << std::endl;
                break;
            }
            else {
                std::cout << "Error: choose a value between 1 and " << _nbContact << std::endl;  
            }
        }
        catch (const std::invalid_argument&) {
            std::cout << "The value is invalid. Please enter an integer." << std::endl;
        }
        catch (const std::out_of_range&) {
            std::cout << "The value is out of range. Please enter a valid index." << std::endl;
        }

        std::cout << "Enter an index: ";
    }
}

void PhoneBook::AddFunction(void) {

    Contact personne;
    std::string value;
    if (_index == 8)
        _index = 0;

    std::cout << "Enter FirstName: ";
    getline(std::cin, value);
    personne.SetFirstName(value);

    std::cout << "Enter LastName: ";
    getline(std::cin, value);
    personne.SetLastName(value);

    std::cout << "Enter NickName: ";
    getline(std::cin, value);
    personne.SetNickName(value);

    std::cout << "Enter PhoneNumber: ";
    getline(std::cin, value);
    personne.SetPhoneNumber(value);

    std::cout << "Enter DarkestSecret: ";
    getline(std::cin, value);
    personne.SetDarkestSecret(value);

    personne.SetIndexContact(_index + 1);
    _contact[_index] = personne;
    _index++;
    if (_nbContact < 8)
        _nbContact++;
}

bool PhoneBook::InputUser(void) {
    std::string str;
    getline(std::cin, str);
    if (str == "EXIT")
    {
        std::cout << "Cya ;)" << std::endl;
        return (false);
    }
    else if (str == "ADD")
    {
        AddFunction();
        return (true);
    }
    else if (str == "SEARCH")
    {
        SearchFunction();
        return (true);
    }
    else 
        return (true);
}