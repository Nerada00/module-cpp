#pragma once

#include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm {

    private:
        std::string _target;
        size_t  _gradeExec;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(RobotomyRequestForm const &src);
        ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
        virtual void execute(Bureaucrat const & executor) const;
};