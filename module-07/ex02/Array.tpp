#include "Array.hpp"

// Constructors
template <typename T>
Array<T>::Array()
{
	_begin = NULL;
	_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_begin = new T[n * sizeof(T)]();
	_size = n;
}

template <typename T>
Array<T>::Array(const Array &copy)
{
	_begin = NULL;
	*this = copy;
}

// Destructor
template <typename T>
Array<T>::~Array()
{
	delete[] _begin;
}

// Operators
template <typename T>
Array<T> & Array<T>::operator=(const Array &assign)
{
	if (this != &assign)
	{
		delete[] _begin;
		_begin = new T[assign._size]();
		std::copy(assign._begin, assign._begin + assign._size, _begin);
		_size = assign._size;
	}
	return *this;
}

template <typename T>
T & Array<T>::operator[](size_t idx)
{
	if (idx >= _size)
		throw std::out_of_range("Out of range");
	return *(_begin + idx);
}

template <typename T>
size_t Array<T>::size() const
{
	return _size;
}
