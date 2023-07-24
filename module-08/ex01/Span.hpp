#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>
#include <set>
#include <cstdlib>
#include <algorithm>

class Span
{
	public:
		typedef std::multiset<unsigned int>::iterator iterator;

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
		void generate_rand(iterator first, iterator last);
		iterator begin();
		iterator end();
		std::size_t size();
		//void fill(iterator first, iterator last, const unsigned int &nbr);
		
	private:
		std::multiset<unsigned int>::size_type _N;
		std::multiset<unsigned int> _arr;
		std::multiset<unsigned int>::size_type _size;
		unsigned int _shortestSpan;
	
		Span();
		// Operators
		Span & operator=(const Span &assign);
};

#endif