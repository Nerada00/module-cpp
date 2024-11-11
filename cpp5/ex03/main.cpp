# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main(void) {

    std::cout << "\n\n============ 1er TEST ============" << std::endl;
    try
	{
		Bureaucrat b1("test1", 1);
		Bureaucrat b2("test2", 1);
		Bureaucrat b3("test3", 1);
		AForm *form1 = new ShrubberyCreationForm("cabouzir");
		b1.signForm(*form1);
		b1.signForm(*form1);
		b1.executeForm(*form1);
		std::cout << "\n";
		AForm *form2 = new RobotomyRequestForm("cyaid");
		b2.signForm(*form2);
		b2.signForm(*form2);
		b2.executeForm(*form2);
		std::cout << "\n";
		AForm *form3 = new PresidentialPardonForm("abdmessa");
		b3.signForm(*form3);
		b3.signForm(*form3);
		b3.executeForm(*form3);
		std::cout << "\n\n";
		delete form1;
		delete form2;
		delete form3;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    std::cout << "\n\n============ 2eme TEST ===========" << std::endl;
    try
	{
		Bureaucrat b1("test1", 145);
		Bureaucrat b2("test2", 72);
		Bureaucrat b3("test3", 25);
		AForm *form1 = new ShrubberyCreationForm("cabouzir");
		b1.signForm(*form1);
		b1.executeForm(*form1);
		std::cout << "\n";
		AForm *form2 = new RobotomyRequestForm("cyaid");
		b2.signForm(*form2);
		b2.executeForm(*form2);
		std::cout << "\n";
		AForm *form3 = new PresidentialPardonForm("abdmessa");
		b3.signForm(*form3);
		b3.executeForm(*form3);
		std::cout << "\n\n";
		delete form1;
		delete form2;
		delete form3;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    std::cout << "\n\n============ 3eme TEST ===========" << std::endl;
    try
	{
		Bureaucrat b1("test1", 137);
		Bureaucrat b2("test2", 45);
		Bureaucrat b3("test3", 5);
		AForm *form1 = new ShrubberyCreationForm("cabouzir");
		b1.signForm(*form1);
		b1.executeForm(*form1);
		std::cout << "\n";
		AForm *form2 = new RobotomyRequestForm("cyaid");
		b2.signForm(*form2);
		b2.executeForm(*form2);
		std::cout << "\n";
		AForm *form3 = new PresidentialPardonForm("abdmessa");
		b3.signForm(*form3);
		b3.executeForm(*form3);
		std::cout << "\n\n";
		delete form1;
		delete form2;
		delete form3;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}