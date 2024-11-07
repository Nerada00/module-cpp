#include "Bureaucrat.hpp"

// Constructor and Destructor
Bureaucrat::Bureaucrat(): _name("Default"), _grade(150) {
    // std::cout << "Bureaucrat " << this->getName() << " Constructor called with grade of "<< this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &str, int value): _name(str), _grade(value) {
    // std::cout << "Bureaucrat " << this->getName() << " Constructor called with grade of "<< this->getGrade() << std::endl;
    if (value > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (value < 1)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = value;
    
}

Bureaucrat::~Bureaucrat() {
    // std::cout << "Bureaucrat Destructor called" << std::endl;
}

// incrementation and decrementation function

void    Bureaucrat::decrementGrade(void)
{
    std::cout << "grade is decremented" << std::endl;
    if (this->_grade +1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade +=1;

}

void    Bureaucrat::incrementGrade(void)
{
    std::cout << "grade is incremented" << std::endl;
    if (this->_grade -1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade -=1;
}

// Subclass member function

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat: Grade too hight\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat: Grade too low\n");
}

// Getters and setters

const std::string Bureaucrat::getName(void) const {
    return (this->_name);
}

int Bureaucrat::getGrade(void) const {
    return (this->_grade);
}

void Bureaucrat::setGrade(int value) {
    if (value > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (value < 1)
        throw Bureaucrat::GradeTooHighException();
   this->_grade = value;
}

// Assignement operator

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &rhs) {
    if (&rhs != this)
    {
        this->_grade = rhs.getGrade();
    }
    return (*this);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &Bureaucrat)
{
	out << "name: " <<Bureaucrat.getName() << " and my grade is : " << Bureaucrat.getGrade() << std::endl;
	return (out);
}
