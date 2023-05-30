#include <cstring>

#include "Harl.hpp"

int main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Invalid number of args." << std::endl;
		return 1;
	}
	Norminette norminet;
	const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	std::string av_string(av[1]);
	unsigned int choice = sizeof(levels) / sizeof(*levels);
	for (unsigned int i = 0; i != sizeof(levels) / sizeof(*levels); i++)
	{
		if (levels[i] == av_string)
		{
			choice = i;
			break;
		}
	}

	switch (choice)
	{
	case 0:
		norminet.complain(levels[0]);
		// fall through
	case 1:
		norminet.complain(levels[1]);
		// fall through
	case 2:
		norminet.complain(levels[2]);	
		// fall through
	case 3:
		norminet.complain(levels[3]);
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
	return 0;
}
