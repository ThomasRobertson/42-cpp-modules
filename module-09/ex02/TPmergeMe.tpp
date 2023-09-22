#include <algorithm> //à enlever
#include "TPmergeMe.hpp"

template<class T>
TPmergeMe<T> & TPmergeMe<T>::operator=(const TPmergeMe & assign)
{
	if (this != &assign)
	{
		_values = assign._values;
	}
	return *this;
}

template<class T>
template<class U>
std::vector<std::pair<typename U::value_type, typename U::value_type> > TPmergeMe<T>::create_pairs(const U & value)
{
    std::vector<std::pair<typename U::value_type, typename U::value_type> > pairs;
	for (typename U::const_iterator it = value.begin(); it != value.end(); it++)
	{
		typename U::value_type first_value = *it;
		it++;
		if (it == value.end())
			throw std::runtime_error("Error: creating pair with odd numbers.");
        typename U::value_type second_value = *it;
		if (comp(first_value, second_value))
		{
            typename U::value_type tmp = first_value;
			first_value = second_value;
			second_value = tmp;
		}
		pairs.push_back(std::make_pair(first_value, second_value));
	}
	return pairs;
}

template<class T>
template<class U>
typename U::iterator TPmergeMe<T>::binary_search(U & list, typename U::value_type key,
                                                   typename U::iterator it_mid,
                                                   size_t segment_size)
{
    if (segment_size <= 1)
    {
        if (comp(*it_mid, key))
            return it_mid;
        else
        {
            it_mid++;
            return it_mid;
        }
    }

    else if (comp(*it_mid, key))
    {
        segment_size /= 2;
        for (size_t i = 0; i != segment_size; i++)
            it_mid--;
        return binary_search(list, key, it_mid, segment_size);
    }
    else
    {
        segment_size /= 2;
        for (size_t i = 0; i != segment_size; i++)
            it_mid++;
        return binary_search(list, key, it_mid, segment_size);
    }
}

template<class T>
template<class U>
void TPmergeMe<T>::binary_sort(U & main_list, U & pend_list)
{
    /*if (main_list.size() == 0)
    {
        main_list.push_back(pend_list.front());
        pend_list.erase(pend_list.begin());
    }*/
    size_t total_size;
    typename U::value_type key;
    typename U::iterator pos_insert;
    typename U::iterator it_mid;
    for (typename U::iterator it_pend = pend_list.begin(); it_pend != pend_list.end(); it_pend++)
    {
        total_size = main_list.size();
        key = *it_pend;
        it_mid = main_list.begin();
        for (size_t i = 0; i != total_size / 2; i++)
            it_mid++;
        pos_insert = binary_search(main_list, key, it_mid, total_size / 2);
        main_list.insert(pos_insert, key);
    }
}

template<class T>
template<class U>
U TPmergeMe<T>::sort_list(U & value)
{
	bool is_even = true;
	typename U::value_type straggler;

	if (value.size() % 2 != 0)
	{
        if (value.size() == 1)
            return value;
		is_even = false;
		straggler = value.back();
		value.pop_back();
	}
	typedef std::vector<std::pair<typename U::value_type, typename U::value_type> > pair_t;
	pair_t pairs = create_pairs(value);
    std::sort(pairs.begin(), pairs.end());
    //pair_t sorted_pairs;
    //binary_sort(sorted_pairs, pairs);
    //pairs = sorted_pairs;
	
	U main_list;
	U pend_list;
	{
		typename pair_t::iterator it = pairs.begin();
		main_list.push_back(it->second);
		main_list.push_back(it->first);
		it++;
		while (it != pairs.end())
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

template<class T>
T TPmergeMe<T>::sort()
{
    T values = sort_list(_values);
    _values = values;
    return (values);
}

template<class T>
bool TPmergeMe<T>::comp(const value_type & a, const value_type & b)
{
	return a < b;
}

template<class T>
template<class U>
bool TPmergeMe<T>::comp(const std::pair<U,U> & a, const std::pair<U,U> & b)
{
    //return a < b;
	return comp(a.first, b.first);
}

template<class T>
template<class U>
bool TPmergeMe<T>::comp(const std::pair<value_type,value_type> & a, const std::pair<value_type,value_type> & b)
{
    return a.first < b.first;
}