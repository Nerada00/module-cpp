#pragma once 

#include <iostream>
#include <cctype>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {


    private:

        const std::string _name;
        bool _signed;
        const size_t _gradeToExec;
        const size_t _gradeToSign;

    public:

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception 
        {
            public:
                virtual const char *what() const throw();
        };
        class FormNotSigned : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        AForm();
        AForm (const std::string &Name, const int &GradeSign, const int &GradeExecute);
        AForm(AForm const &src);
        virtual ~AForm();
        AForm &operator=(const AForm &rhs);
        size_t getGradeToSign() const;
        size_t getGradeToExec() const;
        std::string getName() const;
        bool getSigned() const;
        void beSigned (const Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, AForm const &AForm);