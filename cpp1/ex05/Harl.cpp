#include "Harl.hpp"

Harl::Harl(void) {
    _ptr[0] = &Harl::debug;
    _ptr[1] = &Harl::info;
    _ptr[2] = &Harl::warning;
    _ptr[3] = &Harl::error;
}
void Harl::debug(void) {
    std::cout << "je suis un message de debug" << std::endl;

}
void Harl::info(void) {
    std::cout << "je suis un message d info" << std::endl;

}
void Harl::warning(void) {
    std::cout << "je suis un message de warning" << std::endl;

}
void Harl::error(void) {
    std::cout << "je suis un message d error" << std::endl;

}

void Harl::complain(std::string level) {
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++) {
        if (level == levels[i])
        {
            (this->*_ptr[i])();
            return;
        }
    }
    std::cout << "no level for this input" << std::endl;
}