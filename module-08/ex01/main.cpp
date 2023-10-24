#include "Span.hpp"
#include <climits>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define MEDIUM_SIZE 20000
#define BIG_SIZE 100000

int main()
{
	Span sp = Span(7);

	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	assert((sp.shortestSpan() == 2));
	assert((sp.longestSpan() == 14));
	std::cout << "\nShort size shortest span : "<<sp.shortestSpan() << std::endl;
	std::cout << "Short size longuest span : "<< sp.longestSpan() << std::endl;
	sp.addNumber(9);
	assert((sp.shortestSpan() == 0));
	std::cout << "Short size shortest span : "<<sp.shortestSpan() << std::endl;
	sp.addNumber(0);
	assert((sp.longestSpan() == 17));
	std::cout << "Short size longuest span : "<< sp.longestSpan() << std::endl;
	try
	{
		sp.addNumber(11);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::srand(std::time(NULL));

	Span bigSpan(MEDIUM_SIZE);
	for (size_t i = 0; i != MEDIUM_SIZE / 2; i++)
	{
		bigSpan.addNumber(std::rand());
	}
	std::cout << "\nMedium size shortest span : "<<bigSpan.shortestSpan() << std::endl;
	std::cout << "Medium size longuest span : "<< bigSpan.longestSpan() << std::endl;
	for (size_t i = 0; i != MEDIUM_SIZE / 2; i++)
	{
		bigSpan.addNumber(std::rand());
	}
	std::cout << "Medium size shortest span : "<<bigSpan.shortestSpan() << std::endl;
	std::cout << "Medium size longuest span : "<< bigSpan.longestSpan() << std::endl;

	Span bigBigSpan(BIG_SIZE);
	for (size_t i = 0; i != BIG_SIZE; i++)
	{
		bigBigSpan.addNumber(std::rand());
	}
	std::cout << "\nBig size shortest span : "<<bigBigSpan.shortestSpan() << std::endl;
	std::cout << "Big size longuest span : "<< bigBigSpan.longestSpan() << std::endl;
	try
	{
		bigBigSpan.addNumber(11);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Span BigRandom(BIG_SIZE);
	BigRandom.generate_rand();
	bigBigSpan.addNumber(BigRandom.begin(), BigRandom.end());
	std::cout << "\nBig size total size : "<<bigBigSpan.size() << std::endl;
	std::cout << "\nBig size shortest span : "<<bigBigSpan.shortestSpan() << std::endl;
	std::cout << "Big size longuest span : "<< bigBigSpan.longestSpan() << std::endl;

	BigRandom.generate_rand();
	bigBigSpan.addNumber(BigRandom.begin(), BigRandom.end());
	std::cout << "\nBig size total size : "<<bigBigSpan.size() << std::endl;
	std::cout << "\nBig size shortest span : "<<bigBigSpan.shortestSpan() << std::endl;
	std::cout << "Big size longuest span : "<< bigBigSpan.longestSpan() << std::endl;
	return 0;
}