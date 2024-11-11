#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("Default"), _signed(false), _gradeToExec(150), _gradeToSign(150) {}

Form::Form ( const std::string &Name, const int &GradeSign, const int &GradeExec ) : _name(Name), _signed(false), _gradeToExec(GradeExec), _gradeToSign(GradeSign)
{
	if (GradeSign <= 0 || GradeExec <= 0)
		throw Form::GradeTooHighException();
	else if ( GradeSign > 150 || GradeExec > 150 )
		throw Form::GradeTooLowException();
}

Form::Form(Form const &src): _name(src.getName()), _signed(src.getSigned()), _gradeToExec(src.getGradeToExec()), _gradeToSign(src.getGradeToSign()) {
    if (src.getGradeToExec() <= 0 || src.getGradeToSign() <= 0)
        throw Form::GradeTooHighException();
    else if (src.getGradeToExec() >= 150 || src.getGradeToSign() >= 150)
        throw Form::GradeTooLowException();
}

Form::~Form() {}

Form &Form::operator=(const Form &rhs) {
	if (this == &rhs)
		return (*this);
	this->_signed = rhs.getSigned();
	return (*this);
}

std::string Form::getName()const { return (this->_name); }

bool Form::getSigned()const { return (this->_signed); }

size_t Form::getGradeToSign()const { return (this->_gradeToSign); }

size_t Form::getGradeToExec()const { return (this->_gradeToExec); }

const char* Form::GradeTooHighException::what() const throw() {
    return ("Form: Grade too high\n");
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("Form: Grade too Low\n");
}

void Form::beSigned (const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, Form const &Form) {
    out << "name: " << Form.getName() << " grade to execute: " << Form.getGradeToExec()  << " grade to sign: " << Form.getGradeToSign() << " is signed: " << Form.getSigned() << std::endl;
    return (out);    
}