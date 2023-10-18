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

	T sort()
	{
		T values = sort_list(_values);
		_values = values;
		return (values);
	}
    T get_values() const {return _values;}

	private :
	T _values;

    std::pair<T, T> create_pairs(const T & values)
	{
		T first_list;
		T second_list;
		for (typename T::const_iterator it = values.begin(); it != values.end(); std::advance(it, 2))
		{
			typename T::const_iterator it_for = it;
			typename T::value_type first_value = *it_for;
			it_for++;
			if (it_for == values.end())
				throw std::runtime_error("Error: creating pair with odd numbers.");
			typename T::value_type second_value = *it_for;
			if (first_value < second_value)
				std::swap(first_value, second_value);
			first_list.push_back(first_value);
			second_list.push_back(second_value);
		}
		return std::make_pair(first_list, second_list);
	}

    void binary_sort(T &main_list, T &pend_list)
	{
		for (typename T::iterator it_pend = pend_list.begin(); it_pend != pend_list.end(); it_pend++)
			binary_insert(main_list, *it_pend);
	}

    template<class U>
    void binary_insert(U & list, typename U::value_type key)
	{
		int low = 0;
		int high = list.size();
		typename T::iterator it_mid = list.begin();
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

	T sort_list(T value)
	{
		if (value.size() <= 1)
			return value;
		bool is_even = true;
		typename T::value_type straggler;
		if (value.size() % 2 != 0)
		{
			is_even = false;
			straggler = value.back();
			value.pop_back();
		}

		std::pair<T, T> pairs = create_pairs(value);
		T main_list = pairs.first;
		T pend_list = pairs.second;
		main_list = sort_list(main_list);

		binary_sort(main_list, pend_list);
		if (!is_even)
		{
			T straggler_list;
			straggler_list.push_back(straggler);
			binary_sort(main_list, straggler_list);
		}
		return (main_list);
	}
};
