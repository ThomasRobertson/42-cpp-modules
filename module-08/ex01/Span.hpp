#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>
#include <set>
#include <cstdlib>
#include <algorithm>
#include <limits>
#include <ctime>

class Span
{
	public:
		typedef std::multiset<unsigned int>::iterator iterator;
		typedef std::multiset<unsigned int>::const_iterator const_iterator;

		// Constructors
		Span(const size_t N);
		Span(const Span &copy);
		
		// Destructor
		~Span();
		
		// Exceptions
		class full : public std::exception {
			virtual const char* what() const throw();
		};
		class empty : public std::exception {
			virtual const char* what() const throw();
		};
		class tooFewNumbers : public std::exception {
			virtual const char* what() const throw();
		};

		void addNumber(unsigned int nbr);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		void generate_rand();
		void addNumber(const_iterator first, const_iterator last);
		iterator begin();
		iterator end();
		std::multiset<unsigned int>::size_type size();
		//void fill(iterator first, iterator last, const unsigned int &nbr);
		
	private:
		size_t _N;
		std::multiset<unsigned int> _arr;
		unsigned int _shortestSpan;
	
		Span();
		// Operators
		Span & operator=(const Span &assign);
};

#endif