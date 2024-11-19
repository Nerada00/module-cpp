#include "Array.hpp"

int main()
{
    try {
        Array<std::string> str(3);
        std::cout << "\nSize of Array is " << str.size() << '\n';
        str[0] = "coucou";  
        str[1] = "c est";  
        str[2] = "moi";
        std::cout << str << '\n';
    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }

    try {

        Array<int> str2(3);
        std::cout << "\nSize of Array is " << str2.size() << '\n';
        str2[0] = 1;  
        str2[1] = 2;  
        str2[2] = 3;
        std::cout << str2 << "\n";
    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }

    try {
        Array<float> str3(3);
        std::cout << "\nSize of Array is " << str3.size() << '\n';
        str3[0] = 1.1f;  
        str3[1] = 2.1f;  
        str3[2] = 3.1f;
        std::cout << str3 << "\n";
    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
    // OOB
    try {
        Array<int> str(3);
        std::cout << "\nSize of Array is " << str.size() << '\n';
        str[0] = 59;
        str[1] = 54;
        str[2] = 51;
        std::cout << str[3] << '\n';
    }
    catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}