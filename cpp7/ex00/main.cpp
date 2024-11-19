#include "whatever.hpp"

int main() {
    int a = 100;
    int b = 42;
    char c = 'z';
    char d = 'y';
    std::string str1 = "coucou";
    std::string str2 = "bonjour";

    std::cout << "before a = " << a << '\n';
    std::cout << "before b = " << b << '\n';
    swap(a, b);
    std::cout << "\n =====SWAPING=====\n" << '\n';

    std::cout << "after a = " <<a << '\n';
    std::cout << "after b = " <<b << "\n\n";

    std::cout << "The min value is " << min(a, b) << '\n';
    std::cout << "The max value is " << max(a, b) << "\n\n";

    std::cout << "before c = " << c << '\n';
    std::cout << "before d = " << d << '\n';
    swap(c, d);
    std::cout << "\n =====SWAPING=====\n" << '\n';

    std::cout << "after c = " << c << '\n';
    std::cout << "after d = " << d << "\n\n";

    std::cout << "The min value is " << min(str1, str2) << '\n';
    std::cout << "The max value is " << max(str1, str2) << "\n\n";

    std::cout << "before str1 = " << str1 << '\n';
    std::cout << "before str2 = " << str2 << '\n';
    swap(str1, str2);
    std::cout << "\n =====SWAPING=====\n" << '\n';

    std::cout << "after str1 = " << str1 << '\n';
    std::cout << "after str2 = " << str2 << "\n\n";

    std::cout << "The min value is " << min(str1, str2) << '\n';
    std::cout << "The max value is " << max(str1, str2) << '\n';

}