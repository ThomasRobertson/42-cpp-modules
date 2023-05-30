#include <cstring>

#include "Harl.hpp"

int main ()
{
	Harl karen;
	const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR", "42", ""};

	for (unsigned int i = 0; i < sizeof(levels) / sizeof(*levels); i++)
		karen.complain(levels[i]);
	return 0;
}
