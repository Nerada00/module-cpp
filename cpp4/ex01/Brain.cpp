#include "Brain.hpp"

Brain::Brain(void) {
    std::cout << "Brain construcor called" << std::endl;
}

Brain::~Brain(void) {
    std::cout << "Brain destrucor called" << std::endl;
}

std::string Brain::getIdeas(void) const {
    return *this->_ideas;
}


void Brain::setIdeas(std::string *idea) {
    for (int i = 0; i < 100; i++) {
            if (idea[i].empty())
                break;
            else
                this->_ideas[i] = idea[i];
    }
}