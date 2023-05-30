#include "Harl.hpp"

void Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "You should keep your code clear and consice." << std::endl << std::endl;
}

void Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "Huum, you have to limit yourself to 4 arguments per function max." << std::endl
		<< "If you can't go that, you should learn how to be a better programmer." << std::endl << std::endl;
}

void Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "25 lines and 80 characters max." << std::endl
		<< "Any more and you're an idiot and should give up coding." << std::endl << std::endl;
}

void Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "WHILE LOOPS ARE THE ONLY TRUE FORM OF LOOP ALLOWED." << std::endl
		<< "IF YOU A REAL DEVELOPER, YOU SHOULD BE ABLE TO ONLY USE THESE" << std::endl
		<< "GET THESE FUCK*NG FOR LOOPS OUT OF MY FUCK*NG VIEW YOU FUCK*NG F*CK" << std::endl << std::endl;
}

void Harl::complain(std::string level)
{
	const FunctionPointer  functions[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	const std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i != sizeof(levels) / sizeof(*levels); i++)
	{
		if (levels[i].compare(level) == 0)
			(this->*functions[i])();
	}
}