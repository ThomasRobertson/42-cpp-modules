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
	//pair_t pairs(value.size() / 2);
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
    if (segment_size == 0)
    {
        if (!comp(*it_mid, key))
            return it_mid;
        else
        {
            it_mid--;
            return it_mid;
        }
    }

    else if (comp(*it_mid, key))
    {
        segment_size /= 2;
        for (size_t i = 0; i != segment_size; i++)
            it_mid++;
        return binary_search(list, key, it_mid, segment_size);
    }
    else
    {
        segment_size /= 2;
        for (size_t i = 0; i != segment_size; i++)
            it_mid--;
        return binary_search(list, key, it_mid, segment_size);
    }
}

template<class T>
template<class U>
void TPmergeMe<T>::binary_sort(U & main_list, U & pend_list)
{
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

/*template <class T, class Pred = std::less<T> >
struct sort_pair_first {
    bool operator()(const std::pair<T,T>&left, const std::pair<T,T>&right) {
        return TPmergeMe<T>::comp(left.first, right.first);
    }
}; */

/*
template<class T>
template<class U>
U TPmergeMe<T>::binary_sort(U & main_list, U & pend_list)
{
    typename U::value_type value = *(pend_list.begin());
    size_t total_size = main_list.size();
    size_t n = 0;
    while (n < total_size)
    {
        size_t middle = (n + total_size) / 2;
        typename U::iterator it = main_list.begin();
        for (size_t i = 0; i != middle; i++)
            it++;
        if (comp(value, *it))
            n = middle + 1;
        else
            total_size = middle;
        n++;
    }
} */

template<class T>
template<class U>
U TPmergeMe<T>::sort_list(U & value)
{
	bool is_even = true;
	typename U::value_type straggler;

	if (value.size() % 2 != 0)
	{
		is_even = false;
		straggler = value.back();
		value.pop_back();
	}
	typedef std::vector<std::pair<typename U::value_type, typename U::value_type> > pair_t;
	pair_t pairs = create_pairs(value);
    std::sort(pairs.begin(), pairs.end());
	
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

/* 	T::iterator itp = pend_list.begin();
	T::iterator it = main_list.begin();

	while (itp != pend_list.end() && it != main_list.end())
	{
		std::cout << "[" << *it << ";" << *itp << "]\n";

		if (itp != pend_list.end())
			itp++;
		if (it != main_list.end())
			it++;
	} */
	std::cout << "TOTO\n";
	main_list = sort_list(main_list);
/* 	itp = pend_list.begin();
	it = main_list.begin();

	while (itp != pend_list.end() && it != main_list.end())
	{
		std::cout << "[" << *it << ";" << *itp << "]\n";

		if (itp != pend_list.end())
			itp++;
		if (it != main_list.end())
			it++;
	} */

	(void)is_even;
	(void)straggler;
}

template<class T>
void TPmergeMe<T>::push_back(const std::string & value_str)
{
	_values.push_back(str2nbr<value_type>(value_str));
}

template<class T>
template<class U>
U TPmergeMe<T>::str2nbr(std::string const & s)
{
	U i;
    std::stringstream ss;
	ss << s;
    ss >> i;
    if (ss.fail())
        throw std::runtime_error("Error: cannot convert value, invalid input.");
/* 	else if (!s.empty())
		throw std::runtime_error("Error: str should be empty."); */
    return i;
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
bool TPmergeMe<T>::comp(const U & a, const U & b)
{
	return comp(a->first, b->first);
}
