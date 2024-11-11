#pragma once 

#include <iostream>
#include <cctype>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

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

    private:

        const std::string _name;
        bool _signed;
        const size_t _gradeToExec;
        const size_t _gradeToSign;

    public:

        Form();
        Form (const std::string &Name, const int &GradeSign, const int &GradeExecute);
        Form(Form const &src);
        ~Form();
        Form &operator=(const Form &rhs);
        void beSigned (const Bureaucrat &bureaucrat);
        bool getSigned() const;
        std::string getName() const;
        size_t getGradeToSign() const;
        size_t getGradeToExec() const;
};

std::ostream &operator<<(std::ostream &out, Form const &Form);