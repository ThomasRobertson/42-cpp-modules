#include "PmergeMe.hpp"
#include <cstdlib>

int main (int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "Error: Invalid number of args. \n";
		return EXIT_FAILURE;
	}
    try {
        PmergeMe PMM(av);
		PMM.sort();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
	return EXIT_SUCCESS;
}
