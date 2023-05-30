#include <cstring>

#include "Harl.hpp"

int main ()
{
	Norminette norminet;
	const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR", "42", ""};

	for (unsigned int i = 0; i < sizeof(levels) / sizeof(*levels); i++)
		norminet.complain(levels[i]);
	return 0;
}
