#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("Default"), _signed(false), _gradeToExec(150), _gradeToSign(150) {}

AForm::AForm ( const std::string &Name, const int &GradeSign, const int &GradeExec ) : _name(Name), _signed(false), _gradeToExec(GradeExec), _gradeToSign(GradeSign)
{
	if (GradeSign <= 0 || GradeExec <= 0)
		throw AForm::GradeTooHighException();
	else if ( GradeSign > 150 || GradeExec > 150 )
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &src): _name(src.getName()), _signed(src.getSigned()), _gradeToExec(src.getGradeToExec()), _gradeToSign(src.getGradeToSign()) {
    if (src.getGradeToExec() <= 0 || src.getGradeToSign() <= 0)
        throw AForm::GradeTooHighException();
    else if (src.getGradeToExec() >= 150 || src.getGradeToSign() >= 150)
        throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &rhs) {
	if (this == &rhs)
		return (*this);
	this->_signed = rhs.getSigned();
	return (*this);
}

std::string AForm::getName()const { return (this->_name); }

bool AForm::getSigned()const { return (this->_signed); }

size_t AForm::getGradeToSign()const { return (this->_gradeToSign); }

size_t AForm::getGradeToExec()const { return (this->_gradeToExec); }

const char *AForm::GradeTooHighException::what() const throw() {
    return ("Form: Grade too high\n");
}

const char *AForm::GradeTooLowException::what() const throw() {
    return ("Form: Grade too Low\n");
}

const char *AForm::FormNotSigned::what() const throw() {
    return ("Form: Form not signed\n");
}

void AForm::beSigned (const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, AForm const &AForm) {
    out << "name: " << AForm.getName() << " grade to execute: " << AForm.getGradeToExec()  << " grade to sign: " << AForm.getGradeToSign() << " is signed: " << AForm.getSigned() << std::endl;
    return (out);    
}