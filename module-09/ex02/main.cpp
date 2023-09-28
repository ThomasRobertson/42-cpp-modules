#include "PmergeMe.hpp"
#include <cstdlib>

int main (int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "Error: Invalid number of args. \n";
		return EXIT_FAILURE;
	}
    PmergeMe PMM;
    try {
        PMM.get_values(av);
    }
    catch (const std::exception& e) {
        std::cerr << e.what();
    }
	PMM.sort();
	return EXIT_SUCCESS;
}