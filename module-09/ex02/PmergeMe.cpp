#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy) { *this = copy; }

PmergeMe::PmergeMe(char **av) { getValues(av); }

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &assign) {
	if (this != &assign) {
		_valuesVector = assign._valuesVector;
		_valuesList = assign._valuesList;
	}
	return *this;
}

void PmergeMe::getValues(char **av) {
	std::list<valueType> lst;
	std::vector<valueType> vec;
	for (size_t i = 1; av[i]; i++) {
		validateValues(av[i]);
		lst.push_back(strtol(av[i], NULL, 10));
		vec.push_back(strtol(av[i], NULL, 10));
	}
	_valuesList = TPmergeMe<std::list<valueType> >(lst);
	if (!noDuplicatesFind(_valuesList.getValues())) throw std::invalid_argument("Duplicates find in std::list.");
	_valuesVector = TPmergeMe<std::vector<valueType> >(vec);
	if (!noDuplicatesFind(_valuesVector.getValues())) throw std::invalid_argument("Duplicates find in std::vector.");
}

void PmergeMe::validateValues(char *av) {
	if (av == NULL) throw std::invalid_argument("Empty argument.");
	if (std::strlen(av) == 0) throw std::invalid_argument("Argument of size 0.");
	for (size_t i = 0; av[i]; i++) {
		if (!std::isdigit(av[i])) {
			std::string exception_string = "invalid input : ";
			exception_string += av;
			throw std::invalid_argument(exception_string);
		}
	}
}

void PmergeMe::sort() {
	printValue(_valuesList.getValues());
	_valuesList.sort();
	if (isSorted(_valuesList.getValues()))
		std::cout << "List is sorted.\n";
	else
		std::cout << "List is NOT sorted.\n";
	printValue(_valuesList.getValues());

	_valuesVector.sort();
	if (isSorted(_valuesVector.getValues()))
		std::cout << "Vector is sorted.\n";
	else
		std::cout << "Vector is NOT sorted.\n";
	printValue(_valuesVector.getValues());
}
