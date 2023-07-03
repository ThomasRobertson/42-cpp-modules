#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template<typename T>
void iter(T* begin, size_t size, void (*f)(T &))
{
	for (size_t i = 0; i != size; i++)
		f(begin[i]);
}

template<typename T>
void iter(T* begin, size_t size, void (*f)(T const &))
{
	for (size_t i = 0; i != size; i++)
		f(begin[i]);
}

template<typename T>
void display(T const & input)
{
	std::cout << input << ", ";
}

template<typename T>
void increment(T & input)
{
	input++;
}

#endif // !ITER_HPP