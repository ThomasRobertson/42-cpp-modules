#include <cstring>

#include "NotLooserSed.hpp"

int main (int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Invalid number of args." << std::endl;
		return 1;
	}
	if (std::strlen(av[1]) == 0 || std::strlen(av[2]) == 0 || std::strlen(av[3]) == 0)
	{
		std::cout << "Empty arg." << std::endl;
		return 1;
	}
	std::ofstream in_file(av[1], std::ios_base::in);
	if (!in_file.is_open())
	{
		std::cout << "Could not open " << av[1] << std::endl;
		return 1;
	}

	NotLooserSed Sed(in_file);
	Sed.replace(av[2], av[3]);

	std::string in_filename(av[1]);
	std::string out_filename = in_filename + ".replace";

	std::ofstream out_file(out_filename.c_str(), std::ios_base::out | std::ios_base::trunc);
	if (!out_file.is_open())
	{
		in_file.close();
		return 1;
	}
	Sed.exportToFile(out_file);
	return 0;
}
