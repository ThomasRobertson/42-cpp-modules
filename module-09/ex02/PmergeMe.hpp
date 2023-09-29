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
    PmergeMe(char **av);
	PmergeMe(const PmergeMe & copy);
	~PmergeMe();
	PmergeMe & operator=(const PmergeMe & assign);

	void get_values(char **av);
	static void validate_values(char *av);
	void sort();

	private :
	TPmergeMe<std::list<value_type> > _values_list; // a modifier !
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
            if (it == list.begin())
                continue ;
            if (*it < value)
                return false;
        }
        return true;
    }
};
