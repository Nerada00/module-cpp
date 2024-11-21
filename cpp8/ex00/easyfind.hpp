#include <iostream>
#include <exception>

class NoFind : public std::exception {
    public:
        virtual const char *what() const throw()
        {
            return ("No occurence\n");
        }
};


template <typename T>
void easyfind (T &container, int nb)
{
	if (std::find(container.begin(), container.end(), nb) == container.end())
		throw NoFind();
	else
		std::cout << "Occurence : " << nb << std::endl; 
}
