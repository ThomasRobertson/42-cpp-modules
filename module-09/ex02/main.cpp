#include "PmergeMe.hpp"
#include <cstdlib>

int main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: Invalid number of args. \n";
		return EXIT_FAILURE;
	}
	PmergeMe PMM(av[1]);
	PMM.sort();
	return EXIT_SUCCESS;
}