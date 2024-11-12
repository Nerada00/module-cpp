#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {

    Intern intern;
    AForm *form;

    try {
        form = intern.makeForm("presidential_form", "cyaid");
        std::cout << *form << std::endl;
        delete form;
    }
	catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        form = intern.makeForm("robotomy_form", "cabouzir");
        std::cout << *form << std::endl;
        delete form;
    }
	catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        form = intern.makeForm("shrubbery_form", "abdmessa");
        std::cout << *form << std::endl;
        delete form;
    }
	catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }


    try {
        form = intern.makeForm("form_INEXISTANT", "elvis");
        std::cout << *form << std::endl;
        delete form;
    }
	catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
