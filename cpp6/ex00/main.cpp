#include "ScalarConverter.hpp"

int main(int ac, char **av) {

    if (ac == 2) 
    {
        std::string testValues[] = {"0", "nan", "42.0f"};
        
        for (int i = 0; i < 3; i++)
        {
            std::cout << av[0] << " " << testValues[i] << std::endl;
            ScalarConverter::convert(testValues[i]);
            std::cout << std::endl;

        }
        std::cout << "Votre test Perso" << std::endl;
        ScalarConverter::convert(av[1]);
        return (0);
    }
    else
    {
        std::cerr << "Nombre d'argument invalide !" << std::endl;
        return (1);
    }
}
