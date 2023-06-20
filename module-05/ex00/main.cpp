#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Bob", 150);
		std::cout << bob;
		Bureaucrat lowerBob("LowerBob", 151);
		std::cout << lowerBob;
	}
	catch(const std::exception& e)
	{
		std::cerr << "1 : " << e.what() << '\n';
	}

	try
	{
		Bureaucrat bob("Bob", 1);
		std::cout << bob;
		Bureaucrat higherBob("HigherBob", 0);
		std::cout << higherBob;
	}
	catch(const std::exception& e)
	{
		std::cerr << "2 : " << e.what() << '\n';
	}

	try
	{
		Bureaucrat bob("Bob", 1);
		std::cout << bob;
		bob.increaseGrade();
		std::cout << bob;
	}
	catch(const std::exception& e)
	{
		std::cerr << "3 : " << e.what() << '\n';
	}

	try
	{
		Bureaucrat bob("Bob", 150);
		std::cout << bob;
		bob.decreaseGrade();
		std::cout << bob;
	}
	catch(const std::exception& e)
	{
		std::cerr << "4 : " << e.what() << '\n';
	}
}