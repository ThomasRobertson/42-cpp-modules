#pragma once

#include <list>
#include <vector>
#include <sstream>
#include <iostream>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <cstring>

typedef unsigned int value_type;

template <typename T = std::list<value_type> >
class TPmergeMe
{
	public :
	TPmergeMe() {}
	TPmergeMe(const T & value) : _values(value) {}
	TPmergeMe(const TPmergeMe & copy) {*this = copy;}
	~TPmergeMe() {}
	TPmergeMe & operator=(const TPmergeMe & assign);
    template<class U>
	U sort_list(U & value);
	T sort();
    T get_values() const {return _values;}

	private :
	T _values;

    template <typename U>
    std::vector<std::pair<typename U::value_type, typename U::value_type> > create_pairs(const U & value);
    template<class U>
    void binary_sort(U &main_list, U &pend_list);
    template<class U>
    void binary_insert(U & list, typename U::value_type key);
};

#include "TPmergeMe.tpp"
