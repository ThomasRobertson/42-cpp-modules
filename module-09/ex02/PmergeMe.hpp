#pragma once

#include <string>
#include <iostream>
#include <list>
#include <vector>
#include "TPmergeMe.hpp"

class PmergeMe
{
	public :
	PmergeMe();
	PmergeMe(char *av);
	PmergeMe(const PmergeMe & copy);
	~PmergeMe();
	PmergeMe & operator=(const PmergeMe & assign);

	void get_values(char *av);
	static bool validate_values(char *av);
	void sort();
	
	private :
	TPmergeMe<std::list<unsigned int> > _values_list; // a modifier !
	TPmergeMe<std::vector<unsigned int> > _value_vector;
};