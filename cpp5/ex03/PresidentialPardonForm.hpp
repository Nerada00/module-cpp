#pragma once

#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm {

    private:
        std::string _target;
        size_t  _gradeExec;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(PresidentialPardonForm const &src);
        ~PresidentialPardonForm();
        PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
        virtual void execute(Bureaucrat const & executor) const;
};