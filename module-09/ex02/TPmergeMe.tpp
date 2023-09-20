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
std::vector<std::pair<U, U> > TPmergeMe<T>::create_pairs(const U & value)
{
	//pair_t pairs(value.size() / 2);
	std::vector<std::pair<U, U> > pairs;
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

/*
template<class T>
T & TPmergeMe<T>::insertion_sort_pairs(T & values, typename T::size_type n)
{
	if (n < 1)
    	return values;
	else
	{
		insertion_sort_pairs(values, n - 1);
		typename T::iterator it = values.end();
		value_type last_value = *it;
		it--;
		values.insert(it, last_value);
	}
	return values;
} */

template <class T, class Pred = std::less<T> >
struct sort_pair_first {
    bool operator()(const std::pair<T,T>&left, const std::pair<T,T>&right) {
        Pred p;
        return p(left.first, right.first);
    }
};

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
}

template<class T>
template<class U>
U TPmergeMe<T>::sort_list(U & value)
{
	bool is_even = true;
	typename T::value_type straggler;

	if (value.size() % 2 != 0)
	{
		is_even = false;
		straggler = value.back();
		value.pop_back();
	}
	typedef std::vector<std::pair<U, U> > pair_t;
	pair_t pairs = create_pairs(value);
    std::sort(pairs.begin(), pairs.end(), sort_pair_first<int>());
	
	T main_list;
	T pend_list;
	{
		typename pair_t::iterator it = pairs.begin();
		main_list.push_back(*(it->second));
		main_list.push_back(*(it->first));
		it++;
		while (it != pairs.end())
		{
			main_list.push_back(it->first);
			pend_list.push_back(it->second);
			it++;
		}
	}

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
	_values.push_back(str2nbr(value_str));
}

template<class T>
T TPmergeMe<T>::str2nbr(std::string s)
{
	T i;
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
	sort_list(_values);
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
