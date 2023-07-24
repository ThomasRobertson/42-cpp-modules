#include "Span.hpp"

// Constructors
Span::Span() : _N(0), _size(0)
{
}

Span::Span(const Span &copy) : _N(copy._N), _arr(copy._arr)
{
	//_arr = copy._arr;
}

Span::Span(const size_t N) : _N(N), _size(0)
{
}

// Destructor
Span::~Span()
{
}


// Operators
/* Span & Span::operator=(const Span &assign)
{
	if (_N < assign._N)
		throw Span::
	else
		std::copy(assign.getArr(), assign.getArr() + assign._N, _arr);
	return *this;
} */


// Exceptions
const char * Span::full::what() const throw()
{
	return "Span class is full.";
}
const char * Span::empty::what() const throw()
{
	return "Span class is empty";
}
const char * Span::tooFewNumbers::what() const throw()
{
	return "Span class doesn't countain enought numbers to compute spans.";
}

void Span::addNumber(unsigned int nbr)
{
	if (_size >= _N)
		throw Span::full();
	iterator value = _arr.insert(nbr);
	++_size;
	if (_size < 2)
		return;
	else if (_size == 2)
		_shortestSpan = *(_arr.rbegin()) - *(_arr.begin());
	else
	{
		iterator last_value = _arr.end();
		last_value--;
		if (value != last_value)
		{
			unsigned int shortest_test = *(++value) - *(--value);
			if (shortest_test < _shortestSpan)
				_shortestSpan = shortest_test;
		}
		if (value != _arr.begin())
		{
			unsigned int shortest_test = *(value) - *(--value);
			if (shortest_test < _shortestSpan)
				_shortestSpan = shortest_test;
		}
	}
}

unsigned int Span::longestSpan() const
{
	if (_size < 2)
		throw tooFewNumbers();
	iterator last_value = _arr.end();
	last_value--;
	return (*last_value - *(_arr.begin()));
}

unsigned int Span::shortestSpan() const
{
	if (_size < 2)
		throw tooFewNumbers();
	return _shortestSpan;
}

void Span::generate_rand(iterator first, iterator last)
{
	std::multiset<unsigned int>::size_type size = 0;
	for (iterator i = first; i != last; i++)
	{
		size++;
	}
	_arr.erase(first, last);
	for (std::multiset<unsigned int>::size_type i = 0; i != size; i++)
	{
		_arr.insert(rand());
	}
}

std::size_t Span::size()
{
	return _arr.size();
}

Span::iterator Span::begin()
{
	return _arr.begin();
}

Span::iterator Span::end()
{
	return _arr.end();
}

/* void Span::fill(iterator first, iterator last, const unsigned int &nbr)
{
	std::fill(first, last, nbr);
} */