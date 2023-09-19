#pragma once

#include <list>
#include <vector>
#include <sstream>
#include <iostream>

//template<typename T = std::list<unsigned int> >

typedef unsigned int value_type;
//typedef std::list<value_type> T;

template <typename T = std::list<value_type> >
class TPmergeMe
{
	public :
	//typedef std::vector<std::pair<value_type, value_type> > pair_t;
	TPmergeMe() {}
	TPmergeMe(const T & value) : _values(value) {}
	TPmergeMe(const TPmergeMe & copy) {*this = copy;}
	~TPmergeMe() {}
	TPmergeMe & operator=(const TPmergeMe & assign);
	T sort_list(T & value);
	T sort();
	void push_back(const std::string & value_str);

	private :
	T _values;

	T str2nbr(std::string s);
	std::vector<std::pair<T, T> > create_pairs(const T & value);
	T & insertion_sort_pairs(T & values, T::size_type n);
	bool comp(const value_type & a, const value_type & b);
	bool comp(const T & a, const T & b);
};

#include "TPmergeMe.tpp"