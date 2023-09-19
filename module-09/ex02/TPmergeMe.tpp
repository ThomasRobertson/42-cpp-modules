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
std::vector<std::pair<T, T> > TPmergeMe<T>::create_pairs(const T & value)
{
	//pair_t pairs(value.size() / 2);
	std::vector<std::pair<T, T> > pairs;
	for (typename T::const_iterator it = value.begin(); it != value.end(); it++)
	{
		typename T::value_type first_value = *it;
		it++;
		if (it == value.end())
			throw std::runtime_error("Error: creating pair with odd numbers.");
		typename T::value_type second_value = *it;
		if (comp(first_value, second_value))
		{
			typename T::value_type tmp = first_value;
			first_value = second_value;
			second_value = tmp;
		}
		pairs.push_back(std::make_pair(first_value, second_value));
	}
	return pairs;
}

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
}

template<class T>
T TPmergeMe<T>::sort_list(T & value)
{
	bool is_even = true;
	std::list<value_type>::value_type straggler;

	if (value.size() % 2 != 0)
	{
		is_even = false;
		straggler = value.back();
		value.pop_back();
	}
	typedef std::vector<std::pair<T, T> > pair_t;
	pair_t pairs = create_pairs(value);
	//sort pairs
	
	std::list<value_type> main_list;
	std::list<value_type> pend_list;
	{
		typename pair_t::iterator it = pairs.begin();
		main_list.push_back(*(it->first.begin()));
		it++;
		main_list.push_back(*(it->first.begin()));
		it++;
		while (it != pairs.end())
		{
			main_list.push_back(it->first);
			main_list.push_back(it->second);
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
bool TPmergeMe<T>::comp(const T & a, const T & b)
{
	comp(a->first, b->first);
}
