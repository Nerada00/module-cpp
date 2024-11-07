#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <cctype>
#include <stdexcept>

class Bureaucrat {

    private:
        const std::string _name;
        int _grade;

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
        ~Bureaucrat();
        const std::string getName(void) const;
        int getGrade(void) const;
        void setGrade(int value);
        void incrementGrade(void);
        void decrementGrade(void);
        Bureaucrat  &operator=(const Bureaucrat &rhs);
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &Bureaucrat);

#endif