#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &src) {
    (void)src;
}

Intern::~Intern() {}

Intern &Intern::operator=(Intern const &rhs) {
    (void)rhs;
    return *this;
}

const char *Intern::FormDoesNotExistException::what() const throw() {
    return "Error: The requested form does not exist.";
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
    std::cout << "Intern creates Presidential Pardon Form" << std::endl;
    return (new PresidentialPardonForm(target));
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
    std::cout << "Intern creates Robotomy Request Form" << std::endl;
    return (new RobotomyRequestForm(target));
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) {
    std::cout << "Intern creates Shrubbery Creation Form" << std::endl;
    return (new ShrubberyCreationForm(target));
}


AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    std::string formNames[] = {"presidential_form", "robotomy_form", "shrubbery_form"};

    AForm* (Intern::*createFuncs[])(const std::string&) = {
        &Intern::createPresidentialPardonForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createShrubberyCreationForm
    };
    for (int i = 0; i < 3; ++i) {
        if (formNames[i] == formName) {
            return (this->*createFuncs[i])(target);
        }
    }

    throw FormDoesNotExistException();
}
