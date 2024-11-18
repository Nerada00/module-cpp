#pragma once

#include <iostream>
#include <stdint.h> 

struct Data {
    int id;
    std::string name;
};

class Serializer {

    private:

        Serializer();
        Serializer(const Serializer &src);
        Serializer &operator=(const Serializer &);

    public:

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};
