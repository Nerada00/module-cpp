#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("Default Robotomy"), _gradeExec(45) {}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) { *this = src; }
RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm("RobotomyRequestForm", 72, 45), _target(target), _gradeExec(45) {}
RobotomyRequestForm::~RobotomyRequestForm() {} ;

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw AForm::FormNotSigned();
	if (executor.getGrade() > this->_gradeExec)
		throw AForm::GradeTooLowException();
	std::cout << this->_target << " has been robotomized successfully 50% of the time." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
    this->_target = rhs._target;
    this->_gradeExec = rhs._gradeExec;
    return (*this);
}
