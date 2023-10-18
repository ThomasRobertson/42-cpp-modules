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
	TPmergeMe & operator=(const TPmergeMe & assign)
	{
		if (this != &assign)
		{
			_values = assign._values;
		}
		return *this;
	}

    template<class U>
	U sort_list(U & value)
	{
		if (value.empty())
			return value;
		bool is_even = true;
		typename U::value_type straggler;
		if (value.size() % 2 != 0)
		{
			is_even = false;
			straggler = value.back();
			value.pop_back();
		}

		typedef std::vector<std::pair<typename U::value_type, typename U::value_type> > pair_t;
		pair_t unsorted_pairs = create_pairs(value);
		pair_t sorted_pairs;
		binary_sort(sorted_pairs, unsorted_pairs);

		U main_list;
		U pend_list;
		{
			typename pair_t::iterator it = sorted_pairs.begin();
			main_list.push_back(it->second);
			main_list.push_back(it->first);
			it++;
			while (it != sorted_pairs.end())
			{
				main_list.push_back(it->first);
				pend_list.push_back(it->second);
				it++;
			}
		}

		binary_sort(main_list, pend_list);
		if (!is_even)
		{
			U straggler_list;
			straggler_list.push_back(straggler);
			binary_sort(main_list, straggler_list);
		}
		return (main_list);
	}
	T sort()
	{
		T values = sort_list(_values);
		_values = values;
		return (values);
	}
    T get_values() const {return _values;}

	private :
	T _values;

    template <typename U>
    std::vector<std::pair<typename U::value_type, typename U::value_type> > create_pairs(const U & value)
	{
		std::vector<std::pair<typename U::value_type, typename U::value_type> > pairs;
		for (typename U::const_iterator it = value.begin(); it != value.end(); it++)
		{
			typename U::value_type first_value = *it;
			it++;
			if (it == value.end())
				throw std::runtime_error("Error: creating pair with odd numbers.");
			typename U::value_type second_value = *it;
			if (first_value < second_value)
				std::swap(first_value, second_value);
			pairs.push_back(std::make_pair(first_value, second_value));
		}
		return pairs;
	}

    template<class U>
    void binary_sort(U &main_list, U &pend_list)
	{
		for (typename U::iterator it_pend = pend_list.begin(); it_pend != pend_list.end(); it_pend++)
			binary_insert(main_list, *it_pend);
	}

    template<class U>
    void binary_insert(U & list, typename U::value_type key)
	{
		int low = 0;
		int high = list.size();
		typename U::iterator it_mid = list.begin();
		while (low < high)
		{
			int mid = std::floor(low + (high - low)/2.0);
			it_mid = list.begin();
			std::advance(it_mid, mid);
			if(*it_mid < key)
				low = mid + 1;
			else
				high = mid;
		}
		list.insert(it_mid, key);
	}
};
