#include "Span.hpp"

// Constructors
Span::Span() : _N(0)
{
}

Span::Span(const Span &copy) : _N(copy._N), _arr(copy._arr), _shortestSpan(copy._shortestSpan)
{
}

Span::Span(const size_t N) : _N(N)
{
}

// Destructor
Span::~Span()
{
}


// Operators
 Span & Span::operator=(const Span &assign)
{
	if (_N < assign._arr.size())
		throw std::out_of_range("Assign array is bigger than target.");
	else
		_arr = std::multiset<unsigned int>(assign._arr.begin(), assign._arr.end());
	return *this;
}


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
	if (_arr.size() >= _N)
		throw Span::full();
	_arr.insert(nbr);
}

unsigned int Span::longestSpan() const
{
	if (_arr.size() < 2)
		throw tooFewNumbers();
	iterator last_value = _arr.end();
	last_value--;	
	return (*(_arr.rbegin()) - *(_arr.begin()));
}

unsigned int Span::shortestSpan() const
{
	if (_arr.size() < 2)
		throw tooFewNumbers();
	
	unsigned int shortSpan = longestSpan();
	Span::iterator it = _arr.begin();
	while(it != _arr.end())
	{
		unsigned int low = *it;
		it++;
		if (it == _arr.end())
			break ;
		unsigned int high = *it;
		if (high - low < shortSpan)
			shortSpan = high - low;
	}
	return shortSpan;
}

void Span::generate_rand()
{
	std::srand(std::time(NULL));
	std::multiset<unsigned int>::size_type size = _arr.size();
	_arr.clear();
	for (std::multiset<unsigned int>::size_type i = 0; i != size; i++)
	{
		_arr.insert(rand());
	}
}

void Span::addNumber(const_iterator first, const_iterator last)
{
    if ( _arr.size() + std::distance(first, last) > _N )
        throw Span::full();
    _arr.insert(first, last);
}

std::multiset<unsigned int>::size_type Span::size()
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