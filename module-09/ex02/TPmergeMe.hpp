#pragma once

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <vector>

typedef unsigned int valueType;

template <typename T = std::list<valueType> >
class TPmergeMe {
   public:
	TPmergeMe() {}
	TPmergeMe(const T &value) : _values(value) {}
	TPmergeMe(const TPmergeMe &copy) { *this = copy; }
	~TPmergeMe() {}
	TPmergeMe &operator=(const TPmergeMe &assign) {
		if (this != &assign) {
			_values = assign._values;
		}
		return *this;
	}

	T sort() {
		T values = sortList(_values);
		_values = values;
		return (values);
	}
	T getValues() const { return _values; }

   private:
	T _values;

	std::pair<T, T> createPairs(const T &values) {
		T firstList;
		T secondList;
		for (typename T::const_iterator it = values.begin(); it != values.end(); std::advance(it, 2)) {
			typename T::const_iterator itFor = it;
			typename T::value_type firstValue = *itFor;
			itFor++;
			if (itFor == values.end()) throw std::runtime_error("Error: creating pair with odd numbers.");
			typename T::value_type secondValue = *itFor;
			if (firstValue < secondValue) std::swap(firstValue, secondValue);
			firstList.push_back(firstValue);
			secondList.push_back(secondValue);
		}
		return std::make_pair(firstList, secondList);
	}

	void insert(T &mainList, T &pendList, size_t advance) {
		typename T::iterator it = pendList.begin();
		std::advance(it, advance);
		typename T::value_type value = *it;
		typename T::iterator pos = binarySearch(mainList, value);
		mainList.insert(pos, value);
	}

	void binarySort(T &mainList, T &pendList) {
		static unsigned int jacobsthalArray[] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691,
												 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765, 2863311531};

		size_t pendSize = pendList.size();
		for (size_t i = 0; i < sizeof(jacobsthalArray) / sizeof(*jacobsthalArray) && i < pendSize; i++) {
			unsigned int jacobsthalNumber = jacobsthalArray[i];
			if (jacobsthalNumber <= 1) {
				insert(mainList, pendList, jacobsthalNumber);
				continue;
			} else if (jacobsthalNumber > pendSize - 1) {
				jacobsthalNumber = pendSize - 1;
			}
			for (size_t pendIndex = jacobsthalNumber; pendIndex > jacobsthalArray[i - 1]; pendIndex--) {
				insert(mainList, pendList, pendIndex);
			}
		}
		if (pendSize - 1 > jacobsthalArray[sizeof(jacobsthalArray) / sizeof(*jacobsthalArray) - 1]) {
			for (size_t pendIndex = pendSize - 1; pendIndex > jacobsthalArray[sizeof(jacobsthalArray) / sizeof(*jacobsthalArray) - 1]; pendIndex--) {
				insert(mainList, pendList, pendIndex);
			}
		}
	}

	typename T::iterator binarySearch(T &list, unsigned int key) {
		typename T::iterator start = list.begin();
		typename T::iterator end = list.end();
		while (std::distance(list.begin(), start) < std::distance(list.begin(), end)) {
			typename T::iterator mid = start;
			std::advance(mid, (std::distance(start, end) / 2));
			if (*mid > key) {
				if (mid == list.begin())
					return mid;
				else {
					typename T::iterator prev = mid;
					prev--;
					if (*prev < key) return mid;
				}
			}
			if (*mid > key) {
				end = mid;
			} else {
				start = mid;
				start++;
			}
		}
		return list.end();
	}

	T sortList(T value) {
		if (value.size() <= 1) return value;
		bool is_even = true;
		typename T::value_type straggler;
		if (value.size() % 2 != 0) {
			is_even = false;
			straggler = value.back();
			value.pop_back();
		}

		std::pair<T, T> pairs = createPairs(value);
		T main_list = pairs.first;
		T pend_list = pairs.second;
		main_list = sortList(main_list);

		binarySort(main_list, pend_list);
		if (!is_even) {
			T straggler_list;
			straggler_list.push_back(straggler);
			binarySort(main_list, straggler_list);
		}
		return (main_list);
	}
};
