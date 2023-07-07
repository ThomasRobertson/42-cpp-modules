#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <cstdlib>
#include <stdexcept>

template <typename T>
class Array
{
	public:
		// Constructors
		Array();
		Array(unsigned int n);
		Array(const Array &copy);
		
		// Destructor
		~Array();
		
		// Operators
		Array & operator=(const Array &assign);
		T & operator[](size_t idx);
		T const & operator[](size_t idx) const;
		//T & operator[]() const;
		
		size_t size() const;
		
	private:
		T *_begin;
		size_t _size;
};

#include "Array.tpp"

#endif // !ARRAY_HPP