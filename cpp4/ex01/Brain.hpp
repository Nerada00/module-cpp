#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <cctype> 
#include <iostream>

class Brain {

    private:
        std::string _ideas[100];

    public:
        Brain(void);
        ~Brain(void);
        std::string getIdeas(void) const;
        void setIdeas(std::string *idea);

};


#endif