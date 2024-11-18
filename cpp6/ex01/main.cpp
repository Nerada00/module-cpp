#include "Serializer.hpp"
#define VERT "\033[32m"
#define ROSE "\033[35m"
#define CYAN "\033[36m"
#define BLANC "\033[0m"
#define ROUGE "\033[31m"

int main(int ac, char **av) {

    if (ac == 2)
    {
        Data original;
        original.id = std::atoi(av[1]);
        original.name = "TEST";

        std::cout << "\nSerialized Data:";
        std::cout << VERT "\nID: " << original.id << ", Name: " << original.name << BLANC<< "\n";
        uintptr_t raw = Serializer::serialize(&original);
    
        std::cout << "\nSerialized value: " << raw << "\n";
    
        Data* deserialized = Serializer::deserialize(raw);
        std::cout << "\nDeserialized Data:\n";
        std::cout << VERT "ID: " << deserialized->id << ", Name: " << deserialized->name << BLANC << "\n";

        if (deserialized == &original)
            std::cout << "\nPointeurs communs:\n\n" << CYAN << deserialized << "\n" << &original << "\n";
        else 
            std::cout << "\nPointeurs different:\n\n" << deserialized << "\n" << &original << BLANC << "\n";

        return (1);
    }
    else 
        return (std::cerr << ROUGE "Entrez une seule valeur\n", 0);
}
