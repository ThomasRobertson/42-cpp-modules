#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe & copy)
{
	*this = copy;
}

PmergeMe::PmergeMe(char **av)
{
	get_values(av);
}

PmergeMe::~PmergeMe()
{

}

PmergeMe & PmergeMe::operator=(const PmergeMe & assign)
{
	if (this != &assign)
	{
		_value_vector = assign._value_vector;
		_values_list = assign._values_list;
	}
	return *this;
}

void PmergeMe::get_values(char **av)
{
    std::list<value_type> lst;
    for (size_t i = 0; av[i]; i++)
    {
        validate_values(av[i]);
        lst.push_back(strtol(av[i], NULL, 10));
    }
    _values_list = lst;
    /*
	std::string values(av);
	size_t pos;

	while ((pos = values.find(' ')) != std::string::npos)
	{
		_value_vector.push_back(values.substr(0, pos));
		_values_list.push_back(strtol(values.substr(0, pos).c_str(), NULL, 0));
		values.erase(0, pos + 1);
	}
	_value_vector.push_back(values);
	_values_list.push_back(values); */
}

bool PmergeMe::validate_values(char *av)
{
	(void)av;
	return true;
}

template <class T>
void PmergeMe::print_value(T value)
{
    for (typename T::iterator it = value.begin(); it != value.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::sort()
{
	//_value_vector.sort_list();
    print_value(_values_list.get_values());
	_values_list.sort();
    print_value(_values_list.get_values());
}