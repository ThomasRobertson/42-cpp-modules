#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe & copy)
{
	*this = copy;
}

PmergeMe::PmergeMe(char *av)
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

void PmergeMe::get_values(char *av)
{
	std::string values(av);
	size_t pos;

	while ((pos = values.find(' ')) != std::string::npos)
	{
		_value_vector.push_back(values.substr(0, pos));
		_values_list.push_back(values.substr(0, pos));
		values.erase(0, pos + 1);
	}
	_value_vector.push_back(values);
	_values_list.push_back(values);
}

bool PmergeMe::validate_values(char *av)
{
	(void)av;
	return true;
}

void PmergeMe::sort()
{
	//_value_vector.sort_list();
	_values_list.sort();
}