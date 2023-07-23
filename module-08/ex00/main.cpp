#include "easyfind.hpp"
#include <cassert>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <iostream>

#define FIRST_ELEM 0
#define CONT_SIZE 20000
#define LAST_ELEM CONT_SIZE - 1
#define VALID_TARGET CONT_SIZE / 10
#define INVALID_TARGET CONT_SIZE

struct Generator {
    Generator(int start);
    int operator() ();
	int _current;
};

Generator::Generator(int start) : _current(start) {}
int Generator::operator() () {return _current++;}

template<typename T>
void test_container(T& container)
{
	Generator g(0);
	std::generate(container.begin(), container.end(), g);
	assert((*(easyfind(container, FIRST_ELEM)) == FIRST_ELEM));
	assert((*(easyfind(container, VALID_TARGET)) == VALID_TARGET));
	assert((*(easyfind(container, LAST_ELEM)) == LAST_ELEM));
	assert((easyfind(container, LAST_ELEM) != container.end()));
	assert((easyfind(container, INVALID_TARGET) == container.end()));
	assert((easyfind(container, -1) == container.end()));
}

int main()
{
	// Vector
	std::vector<int> intVector(CONT_SIZE);
	test_container(intVector);
	std::cout << "Vector valid. \n";
	
	// Deque
	std::deque<int> intDeque(CONT_SIZE);
	test_container(intDeque);
	std::cout << "Deque valid. \n";

 	// List
	std::list<int> intList(CONT_SIZE);
	test_container(intList);
	std::cout << "List valid. \n";
}
