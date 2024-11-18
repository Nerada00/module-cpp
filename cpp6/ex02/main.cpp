#include <iostream>
#include <cmath>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {

    int random = rand() % 3;

    if (random == 0) {
        std::cout << "Generated: A" << std::endl;
        return (new A());
    }
    else if (random == 1) {
        std::cout << "Generated: B" << std::endl;
        return (new B());
    }
    else {
        std::cout << "Generated: C" << std::endl;
        return (new C());
    }
}

void identify(Base* p) {

    if (dynamic_cast<A*>(p)) {
        std::cout << "Type: A" << std::endl;
    } 
    else if (dynamic_cast<B*>(p)) {
        std::cout << "Type: B" << std::endl;
    }
    else if (dynamic_cast<C*>(p)) {
        std::cout << "Type: C" << std::endl;
    } 
    else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p) {

    try 
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a;
    }
    catch (std::exception &error) 
    {
        std::cout << "Catch error in A type: " << error.what() << std::endl;
    }

    try 
    {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        (void)b;
    }
    catch (std::exception &error) 
    {
        std::cout << "Catch error in B type: " << error.what() << std::endl;
    }

    try 
    {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void)c;
    }
    catch (std::exception &error) 
    {
        std::cout << "Catch error in C type: " << error.what() << std::endl;
    }
}

int main()
{
    srand(time(NULL));
    Base *base = generate();
	identify(base);
	identify(*base);

	delete base;
	return (0);
}