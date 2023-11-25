#pragma once

#include <algorithm>
#include <string>
#include <iostream>
#include <list>
#include <vector>
#include "TPmergeMe.hpp"

class PmergeMe
{
	public :
    PmergeMe(char **av);
	PmergeMe(const PmergeMe & copy);
	~PmergeMe();
	PmergeMe & operator=(const PmergeMe & assign);

	void get_values(char **av);
	static void validate_values(char *av);
	void sort();

	private :
	PmergeMe();
	TPmergeMe<std::list<value_type> > _values_list;
	TPmergeMe<std::vector<value_type> > _value_vector;

    template <class T>
    void print_value(T value)
    {
        for (typename T::iterator it = value.begin(); it != value.end(); it++)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    template<class T>
    bool is_sorted(T list)
    {
        typename T::value_type value = list.front();
        for (typename T::iterator it = list.begin(); it != list.end(); it++)
        {
            if (it != list.begin() && *it < value)
                return false;
			value = *it;
        }
        return true;
    }
	template<class T>
	bool no_duplicates_find(T numbers)
	{
		for (typename T::iterator it = numbers.begin(); it != numbers.end(); it++)
		{
			if (std::count(numbers.begin(), numbers.end(), *it) != 1)
				return false;
		}
		return true;
	}
};
