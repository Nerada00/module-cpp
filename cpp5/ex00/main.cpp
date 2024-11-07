#include "Bureaucrat.hpp"

int main(void) {

    // rentre dans le catch car on initie a 151 directement
    std::cout << "\n\n============ 1er TEST ============" << std::endl;
    try {
        Bureaucrat test1("Mario", 151);
        std::cout << "je n apparait pas sur le terminal" << std::endl;
        test1.getName();
    }
    catch ( std::exception &error ) {
		std::cerr << "Enter in catch because : ";
		std::cerr << error.what() << "\n";
	}

    // rentre dans le catch car le grade est par defaut initie a 150 et on le decrement 
    std::cout << "\n============ 2eme TEST ============" << std::endl;
    try {
        Bureaucrat test2;
        std::cout << test2.getGrade() << std::endl;
        test2.decrementGrade();
        std::cout << test2.getGrade() << std::endl;
        std::cout << "je n apparait pas sur le terminal" << std::endl;


    }
    catch ( std::exception &error ) {
		std::cerr << "Enter in catch because : ";
		std::cerr << error.what() << "\n";
	}

    // rentre dans le catch car le grade est initie a 1 et on lincrement 
    std::cout << "\n============ 3eme TEST ============" << std::endl;
    try {
        Bureaucrat test3("Luigi", 1);
        std::cout << test3.getGrade() << std::endl;
        test3.incrementGrade();
        std::cout << test3.getGrade() << std::endl;
        std::cout << "je n apparait pas sur le terminal" << std::endl;
    }
    catch ( std::exception &error ) {
		std::cerr << "Enter in catch because : ";
		std::cerr << error.what() << "\n";
	}

    // va jusqu'au bout du try car aucun probleme
    std::cout << "\n============ 4eme TEST ============" << std::endl;
    try {
        Bureaucrat test4("Luigi", 1);
        std::cout << test4.getGrade() << std::endl;
        test4.decrementGrade();
        std::cout << test4;
        std::cout << "Cette fois ci j'apparais dans le terminal\n" << std::endl;
    }
    catch (std::exception &error) {
		std::cerr << "Enter in catch because : ";
		std::cerr << error.what() << "\n";
	}

}