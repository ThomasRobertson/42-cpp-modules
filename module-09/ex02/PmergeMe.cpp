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
    std::vector<value_type> vec;
    for (size_t i = 1; av[i]; i++)
    {
        validate_values(av[i]);
        lst.push_back(strtol(av[i], NULL, 10));
        vec.push_back(strtol(av[i], NULL, 10));
    }
    _values_list = lst;
    if (std::adjacent_find(lst.begin(), lst.end()) != lst.end())
        throw std::invalid_argument("Duplicates find in std::list.");
    _value_vector = vec;
    if (std::adjacent_find(vec.begin(), vec.end()) != vec.end())
        throw std::invalid_argument("Duplicates find in std::vector.");
}

void PmergeMe::validate_values(char *av)
{
    if (av == NULL)
        throw std::invalid_argument("Empty argument.");
    if (std::strlen(av) == 0)
        throw std::invalid_argument("Argument of size 0.");
    for (size_t i = 0; av[i]; i++)
    {
        if (!std::isdigit(av[i]))
        {
            std::string exception_string = "invalid input : ";
            exception_string += av;
            throw std::invalid_argument(exception_string);
        }
    }
}

void PmergeMe::sort()
{
    print_value(_values_list.get_values());
	_values_list.sort();
    if (is_sorted(_values_list.get_values()))
        std::cout << "List is sorted.\n";
    else
        std::cout << "List is NOT sorted.\n";
    print_value(_values_list.get_values());

    _value_vector.sort();
    if (is_sorted(_value_vector.get_values()))
        std::cout << "Vector is sorted.\n";
    else
        std::cout << "Vector is NOT sorted.\n";
    print_value(_value_vector.get_values());
}
