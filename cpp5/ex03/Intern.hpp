#pragma once
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;

class Intern {

    private:

        AForm* createPresidentialPardonForm(const std::string& target);
        AForm* createRobotomyRequestForm(const std::string& target);
        AForm* createShrubberyCreationForm(const std::string& target);

    public:

        Intern();
        Intern(Intern const &src);
        ~Intern();
        AForm *makeForm(std::string const &form, std::string const &target);
        Intern &operator=(Intern const &rhs);
        class FormDoesNotExistException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

};