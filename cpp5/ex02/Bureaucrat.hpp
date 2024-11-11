#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <cctype>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

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
        void signForm(AForm &form);
        size_t getGrade(void) const;
        void setGrade(size_t value);
        void incrementGrade(void);
        void decrementGrade(void);
        void		executeForm ( AForm const &AForm );
        Bureaucrat  &operator=(const Bureaucrat &rhs);
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &Bureaucrat);

#endif