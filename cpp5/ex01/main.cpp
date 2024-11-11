#include "Bureaucrat.hpp"

int main(void) {

    // peut etre signer car not minimal de 150 et 12 > 150 (en grade)
    std::cout << "\n\n============ 1er TEST ============" << std::endl;
    try 
    {
        Bureaucrat test("El Professor" , 12);
        Form form1("Tokyo", 150, 12);
        test.signForm(form1);
        test.signForm(form1);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    // ne peut etre signer car 12 < 1 (en grade)
    std::cout << "\n============ 2eme TEST ===========" << std::endl;
    try 
    {
        Bureaucrat test("El Professor" , 12);
        Form form1("Tokyo", 1, 12);
        test.signForm(form1);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    // Form peut etre signer car superieur ou egal 12 = 12
    std::cout << "\n============ 3eme TEST ===========" << std::endl;
    try 
    {
        Bureaucrat test("El Professor" , 12);
        Form form1("Tokyo", 12, 12);
        test.signForm(form1);
        test.signForm(form1);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    // Bureaucrat peut signer grade 1 > 12 (en grade)
    std::cout << "\n============ 4eme TEST ===========" << std::endl;
    try 
    {
        Bureaucrat test("El Professor" , 1);
        Form form1("Tokyo", 12, 12);
        std::cout << form1.getSigned() << std::endl;
        form1.beSigned(test);
        std::cout << form1.getSigned() << std::endl;
        test.signForm(form1);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    // ne peut pas signer car grade trop faible 34 < 12 (en grade)
    std::cout << "\n============ 5eme TEST ===========" << std::endl;
    try 
    {
        Bureaucrat test("El Professor" , 34);
        Form form1("Tokyo", 12, 12);
        std::cout << form1.getSigned() << std::endl;;
        form1.beSigned(test);
        std::cout << form1.getSigned() << std::endl;;
        test.signForm(form1);

    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}