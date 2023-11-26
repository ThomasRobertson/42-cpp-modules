#include "PmergeMe.hpp"

#include "TPmergeMe.hpp"

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

bool PmergeMe::sort() {
	timespec start, end;

	std::cout << "Unsorted values : ";
	printValue(_valuesList.getValues());

	// std::clock_t start = std::clock();
	// _valuesList.sort();
	// std::clock_t end = std::clock();
	// double listDuraction = (end - start) / static_cast<double>(CLOCKS_PER_SEC) * 1e6;

	// start = std::clock();
	// _valuesVector.sort();
	// end = std::clock();
	// double vectorDuraction = (end - start) / static_cast<double>(CLOCKS_PER_SEC) * 1e6;

	clock_gettime(CLOCK_REALTIME, &start);

	_valuesList.sort();

	clock_gettime(CLOCK_REALTIME, &end);
	double listDuraction = ((double)(end.tv_sec - start.tv_sec) * 1e9 + (double)(end.tv_nsec - start.tv_nsec)) / 1000;

	clock_gettime(CLOCK_REALTIME, &start);

	_valuesVector.sort();

	clock_gettime(CLOCK_REALTIME, &end);
	double vectorDuraction = ((double)(end.tv_sec - start.tv_sec) * 1e9 + (double)(end.tv_nsec - start.tv_nsec)) / 1000;

	std::cout << "Sorted values : ";
	printValue(_valuesList.getValues());

	std::cout << "Execution time to sort " << _valuesList.getValues().size() << " element(s) in a std::list"
			  << " : " << listDuraction << " microseconds\n";
	std::cout << "Execution time to sort " << _valuesVector.getValues().size() << " element(s) in a std::vector"
			  << " : " << vectorDuraction << " microseconds\n";

	if (isSorted(_valuesList.getValues()) && isSorted(_valuesVector.getValues()))
		return true;
	else
		return false;
}
