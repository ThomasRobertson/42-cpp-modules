#include <cstdlib>

#include "PmergeMe.hpp"

int main(int ac, char** av) {
	if (ac == 1) {
		std::cout << "Error: Invalid number of args. \n";
		return EXIT_FAILURE;
	}
	try {
		PmergeMe PMM(av);
		bool sortReturnValue = PMM.sort();
		if (sortReturnValue == true)
			return EXIT_SUCCESS;
		else {
			return EXIT_FAILURE;
		}
	} catch (const std::exception& e) {
		std::cout << e.what() << "\n";
		return EXIT_FAILURE;
	}
}
