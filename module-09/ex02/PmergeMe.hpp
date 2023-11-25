#pragma once

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "TPmergeMe.hpp"

class PmergeMe {
   public:
	PmergeMe(char **av);
	PmergeMe(const PmergeMe &copy);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &assign);

	void getValues(char **av);
	static void validateValues(char *av);
	void sort();

   private:
	PmergeMe();
	TPmergeMe<std::list<valueType> > _valuesList;
	TPmergeMe<std::vector<valueType> > _valuesVector;

	template <class T>
	void printValue(T value) {
		for (typename T::iterator it = value.begin(); it != value.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	template <class T>
	bool isSorted(T list) {
		typename T::value_type value = list.front();
		for (typename T::iterator it = list.begin(); it != list.end(); it++) {
			if (it != list.begin() && *it < value) return false;
			value = *it;
		}
		return true;
	}
	template <class T>
	bool noDuplicatesFind(T numbers) {
		for (typename T::iterator it = numbers.begin(); it != numbers.end(); it++) {
			if (std::count(numbers.begin(), numbers.end(), *it) != 1) return false;
		}
		return true;
	}
};
