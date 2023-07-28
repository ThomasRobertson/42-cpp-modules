#include "BitcoinExchange.hpp"
#include <cstdlib>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: wrong number of arguments." << std::endl;
		return EXIT_FAILURE;
	}
	std::ifstream data_csv("data.csv");
	std::ifstream input_data(av[1]);
	if (!data_csv.is_open() || !input_data.is_open())
	{
		std::cout << "Error: couldn't not open one or more file(s)." << std::endl;
		return EXIT_FAILURE;
	}
	try
	{
		BitcoinExchange MainExchanger(data_csv);
		MainExchanger.process_input(input_data);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}