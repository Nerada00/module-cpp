#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("Default Presidential"), _gradeExec(5) {}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) { *this = src; }
PresidentialPardonForm::PresidentialPardonForm(std::string const &target): AForm("PresidentialPardonForm", 25, 5), _target(target), _gradeExec(5) {}
PresidentialPardonForm::~PresidentialPardonForm() {} ;

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw AForm::FormNotSigned();
	if (executor.getGrade() > this->_gradeExec)
		throw AForm::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
    this->_target = rhs._target;
    this->_gradeExec = rhs._gradeExec;
    return (*this);
}