#include "easyfind.hpp"
#include <algorithm>
#include <vector>

template<typename T>
typename T::iterator easyfind(T &input, int target)
{
	return std::find(input.begin(), input.end(), target);
}
