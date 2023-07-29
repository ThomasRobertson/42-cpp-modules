#include "RPN.hpp"
#include <cstdlib>
#include <cassert>

#define DEBUG

int main (int ac, char **av)
{
#ifdef DEBUG
	(void)ac;
	(void)av;
	std::cout << "--- CORRECT VALUES ---\n\n";

	std::string RPN_value[] = {"8 9 * 9 - 9 - 9 - 4 - 1 +",
								"7 7 * 7 -", "1 2 * 2 / 2 * 2 4 - +",
								"2 3 +", "4 5 * 2 /", "3 7 + 2 * 4 -",
								"5 1 2 + 4 * + 3 -", "6 2 / 3 * 4 5 + +",
								"8 2 * 5 /", "8 3 + 2 6 * -",
								"9 2 / 3 4 * + 7 -"};
	int RPN_answer[] = {42, 42, 0, 5, 10, 16, 14, 18, 3, -1, 9};
	
	for (size_t i = 0; i != (sizeof RPN_value / sizeof *RPN_value); i++)
	{
		RPN PNL(RPN_value[i].c_str());
		std::cout << "Value " << i + 1 << "/" << sizeof RPN_value / sizeof *RPN_value
			<< " : " << RPN_value[i] << " = ";
		int result = PNL.do_RPN_stuff();
		std::cout << result << " (answer : " << RPN_answer[i] << ")";
		assert(result == RPN_answer[i]);
		std::cout << " -- OK\n";
	}

	std::cout << "\n\n--- INCORRECT CORRECT VALUES ---\n\n";
	std::string incorrent_RPN_value[] = {"(1 + 1)", "toto", "", "1 +", "11+", "10 1 +", "1 + 1", "1 1 =", "1 1 + /",
											"1 1 1 +", "2 3 + +", "4 * 5 2 /", "3 7 + 2 * 4", "5 1 2 + 4 * + 3",
											"6 2 / 3 * 4 + + +", "10 2 * 5 / 3 -", "8 3 + 2 6 * - /", "2 3 + +",
											"4 * 5 2 /", "3 7 + 2 * 4", "5 1 2 + 4 * + 3", "6 2 / 3 * 4 + + +",
											"10 2 * 5 / 3 -", "8 3 + 2 6 * - /", "1 2 + -", "3 4 5 + * 2 - -",
											"9 2 3 + * /", "5 6 + 7 - 8 9 *", "10 2 + 3 4 + + /", "6 7 8 + + + 9 -",
											"12 3 4 + * 5 - /", "2 3 + 4 5 6 + -", "7 8 + * - - 11 /",
											"2 3 + 4 * 5 / 6", "9 8 - 7 * /", "12 3 / 4 + 5 6 / *", "3 4 + 5 6 + 7 8 /",
											"2 3 4 5 + * 6", "5 6 7 + + 8 / -", "8 9 / 10 2 * + 3 -",
											"1 2 + 3 4 * 5 - 6 7 /", "2 3 + 4 5 - * 6 7 /", "4 5 + 6 7 - * 8 9 /",
											"5 6 + 7 8 * - 9 10 /", "9 10 / 8 7 * + 6 5 -", "12 2 / 6 * 3 4 / -",
											"5 6 + 7 8 - 9 10 / *"};
	for (size_t i = 0; i != (sizeof incorrent_RPN_value / sizeof *incorrent_RPN_value); i++)
	{
		RPN PNL(incorrent_RPN_value[i].c_str());
		std::cout << "Value " << i + 1 << "/" << sizeof incorrent_RPN_value / sizeof *incorrent_RPN_value
			<< " : " << incorrent_RPN_value[i] << " = ";
		bool exeption_raised = false;
		int result;
		try
		{
			result = PNL.do_RPN_stuff();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what();
			exeption_raised = true;
		}
		(void)result;
		assert(exeption_raised == true);
		std::cout << " -- OK\n";
	}	

#else
	if (ac != 2)
	{
		std::cout << "Wrong number of args.\n";
		return EXIT_FAILURE;
	}

	RPN PNL(av[1]);
	int result;
	try
	{
		result = PNL.do_RPN_stuff();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return EXIT_FAILURE;
	}
	std::cout << result << std::endl;
	return EXIT_SUCCESS;
#endif // DEBUG
}