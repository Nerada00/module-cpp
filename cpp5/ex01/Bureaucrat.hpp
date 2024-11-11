#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <cctype>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat {

    private:
        const std::string _name;
        size_t _grade;

    public:
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        Bureaucrat();
        Bureaucrat(const std::string &str, int value);
        Bureaucrat (Bureaucrat const & src);
        ~Bureaucrat();
        const std::string getName(void) const;
        void signForm(Form &form);
        size_t getGrade(void) const;
        void setGrade(size_t value);
        void incrementGrade(void);
        void decrementGrade(void);
        Bureaucrat  &operator=(const Bureaucrat &rhs);
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &Bureaucrat);

#endif