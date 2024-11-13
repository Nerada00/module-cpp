#include "Brain.hpp"

Brain::Brain(void) {
    std::cout << "Brain : Construcor Called" << std::endl;
}

Brain::Brain(Brain const &src) {
    *this = src;
}

Brain::~Brain(void) {
    std::cout << "Brain : Destrucor Called" << std::endl;
}

Brain &Brain::operator=( Brain const &rhs )
{
	if ( this != &rhs )
		this->setIdeas(rhs.getIdeas());
	return *this;
}

std::string *Brain::getIdeas(void) const {
    return (std::string*)this->_ideas;
}

void Brain::setIdeas(std::string *idea) {
    for (int i = 0; i < 100; i++) {
            if (idea[i].empty())
                break;
            else
                this->_ideas[i] = idea[i];
    }
}