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
    template<class U>
	U sort_list(U & value);
	T sort();
	void push_back(const std::string & value_str);

	private :
	T _values;

    template<class U>
	U str2nbr(std::string const & s);
    template <typename U>
	std::vector<std::pair<U, U> > create_pairs(const U & value);
	//T & insertion_sort_pairs(T & values, T::size_type n);
	bool comp(const value_type & a, const value_type & b);
    template <class U>
	bool comp(const U & a, const U & b);
    template<class U>
    void binary_sort(U &main_list, U &pend_list);
    template<class U>
    typename U::iterator binary_search(U & list, typename U::value_type key,
                                                       typename U::iterator it_mid,
                                                       size_t segment_size);
};

#include "TPmergeMe.tpp"