#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form form("cerfa 4564", 50, 50);
		std::cout << form << std::endl;
		Form form1("cerfa 4564", 151, 50);
	}
	catch(const std::exception& e)
	{
		std::cerr << " 1 : " << e.what() << "\n\n";
	}

	try
	{
		Form form("cerfa 4564", 50, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << " 2 : " << e.what() << "\n\n";
	}

	try
	{
		Form form("cerfa 4564", 0, 50);
	}
	catch(const std::exception& e)
	{
		std::cerr << " 3 : " << e.what() << "\n\n";
	}	

	try
	{
		Form form("cerfa 4564", 50, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << " 4 : " << e.what() << "\n\n";
	}

	try
	{
        Form form("cerfa 485647", 50, 100);
		form.beSigned(Bureaucrat("bob", 50));
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << " 5 : " << e.what() << "\n\n";
	}

	try
	{
        Form form("cerfa 485647", 50, 100);
		form.beSigned(Bureaucrat("bob", 51));
        std::cout << form;
	}
	catch(const std::exception& e)
	{
		std::cerr << " 6 : " << e.what() << "\n\n";
	}

	try
	{
        Form form("cerfa 485647", 50, 100);
		Bureaucrat bob("bob", 50);
		bob.signForm(form);
        std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << " 7 : " << e.what() << "\n\n";
	}

	try
	{
        Form form("cerfa 485647", 50, 100);
		Bureaucrat bob("bob", 51);
		bob.signForm(form);
        std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << " 8 : " << e.what() << "\n\n";
	}	
}
