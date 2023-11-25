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
		for (typename T::iterator it = pend_list.begin(); it != pend_list.end(); ++it)
		{
			typename T::iterator pos = binary_search(main_list, *it);
			main_list.insert(pos, *it);
		}
	}

	unsigned int jacobsthal(unsigned int n) {
		if (n == 0)
			return 0;
		else if (n == 1)
			return 1;
		else
			return jacobsthal(n-1) + 2 * jacobsthal(n-2);
	}

	typename T::iterator binary_search(T& list, unsigned int key)
	{
		static unsigned int jacob[] = {0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};
		size_t low = 0;
		size_t high = list.size();
		unsigned int mid;
		typename T::iterator it_mid = list.begin();
		while (low < high)
		{
			for (int i = 0; jacob[i] <= high - low - 1; i++)
			{
				mid = jacob[i];
			}
			it_mid = list.begin();
			std::advance(it_mid, mid);
			if(*it_mid < key)
				low = mid + 1;
			else
				high = mid;
		}
		return it_mid;
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
