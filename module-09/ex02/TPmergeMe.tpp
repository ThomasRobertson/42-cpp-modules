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
		if (first_value < second_value)
            std::swap(first_value, second_value);
		pairs.push_back(std::make_pair(first_value, second_value));
	}
	return pairs;
}

template<class T>
template<class U>
void TPmergeMe<T>::binary_insert(U & list, typename U::value_type key)
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

template<class T>
template<class U>
void TPmergeMe<T>::binary_sort(U & main_list, U & pend_list)
{
    for (typename U::iterator it_pend = pend_list.begin(); it_pend != pend_list.end(); it_pend++)
        binary_insert(main_list, *it_pend);
}

template<class T>
template<class U>
U TPmergeMe<T>::sort_list(U & value)
{
    if (value.size() == 1)
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
    // sorted_pairs = sort_list(unsorted_pairs);
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

template<class T>
T TPmergeMe<T>::sort()
{
    T values = sort_list(_values);
    _values = values;
    return (values);
}
