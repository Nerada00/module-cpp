#pragma once

#include <iostream>
#include <cctype>

template <typename T>
void printer(T const &value)
{
    std::cout << value << "\n";
}

template <typename T>
void iter(T *array, size_t len, void (*fct)(T const &))
{
	for (size_t i = 0; i < len; i++)
		fct(array[i]);
}

