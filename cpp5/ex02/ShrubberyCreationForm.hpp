#pragma once

#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm {

    private:
        std::string _target;
        size_t  _gradeExec;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const &target);
        ShrubberyCreationForm(ShrubberyCreationForm const &src);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
        virtual void execute(Bureaucrat const & executor) const;
};