#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat bob("bob", 50);
	Bureaucrat lowerBob("lowerBob", 150);
	Bureaucrat higherBob("higherBob", 1);

	Bureaucrat bureaucrats[] = {Bureaucrat("higherBob", 1), Bureaucrat("bob", 50), Bureaucrat("lowerBob", 150)};

	std::cout << "\n--- ShubberyForm ---\n\n";

	ShrubberyCreationForm ShubberyForm("Shubbery");
	std::cout << "name : " << ShubberyForm.getName()
		<< " grade to sign : " << ShubberyForm.getGradeRequiredToSign()
		<< " grade to execute : " << ShubberyForm.getGradeRequiredToExecute()
		<< std::endl;

	try
	{
		for (size_t i = 0; i != (sizeof bureaucrats / sizeof *bureaucrats); i++)
		{
			bureaucrats[i].executeForm(ShubberyForm);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		for (size_t i = 0; i != (sizeof bureaucrats / sizeof *bureaucrats); i++)
		{
			bureaucrats[i].signForm(ShubberyForm);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    std::cout << std::endl;
	try
	{
		for (size_t i = 0; i != (sizeof bureaucrats / sizeof *bureaucrats); i++)
		{
			bureaucrats[i].executeForm(ShubberyForm);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    std::cout << std::endl;
	try
	{
		for (size_t i = 0; i != (sizeof bureaucrats / sizeof *bureaucrats); i++)
		{
			ShubberyForm.execute(bureaucrats[i]);
            std::cout << "System : " << bureaucrats[i].getName() << " has executed the form.\n";
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n--- RobotomyForm ---\n\n";

	RobotomyRequestForm RobotomyForm("Robotomy");
	std::cout << "name : " << RobotomyForm.getName()
		<< " grade to sign : " << RobotomyForm.getGradeRequiredToSign()
		<< " grade to execute : " << RobotomyForm.getGradeRequiredToExecute()
		<< std::endl;

	try
	{
		for (size_t i = 0; i != (sizeof bureaucrats / sizeof *bureaucrats); i++)
		{
			bureaucrats[i].executeForm(RobotomyForm);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    std::cout << std::endl;
	try
	{
		for (size_t i = 0; i != (sizeof bureaucrats / sizeof *bureaucrats); i++)
		{
			bureaucrats[i].signForm(RobotomyForm);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    std::cout << std::endl;
	try
	{
		for (size_t i = 0; i != (sizeof bureaucrats / sizeof *bureaucrats); i++)
		{
			bureaucrats[i].executeForm(RobotomyForm);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    std::cout << std::endl;
	try
	{
		for (size_t i = 0; i != (sizeof bureaucrats / sizeof *bureaucrats); i++)
		{
			RobotomyForm.execute(bureaucrats[i]);
            std::cout << "System : " << bureaucrats[i].getName() << " has executed the form.\n";
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n--- PresidentialForm ---\n\n";

	PresidentialPardonForm PresidentialForm("Presidential");
	std::cout << "name : " << PresidentialForm.getName()
		<< " grade to sign : " << PresidentialForm.getGradeRequiredToSign()
		<< " grade to execute : " << PresidentialForm.getGradeRequiredToExecute()
		<< std::endl;

	try
	{
		for (size_t i = 0; i != (sizeof bureaucrats / sizeof *bureaucrats); i++)
		{
			bureaucrats[i].executeForm(PresidentialForm);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    std::cout << std::endl;
	try
	{
		for (size_t i = 0; i != (sizeof bureaucrats / sizeof *bureaucrats); i++)
		{
			bureaucrats[i].signForm(PresidentialForm);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    std::cout << std::endl;
	try
	{
		for (size_t i = 0; i != (sizeof bureaucrats / sizeof *bureaucrats); i++)
		{
			bureaucrats[i].executeForm(PresidentialForm);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    std::cout << std::endl;
	try
	{
		for (size_t i = 0; i != (sizeof bureaucrats / sizeof *bureaucrats); i++)
		{
			PresidentialForm.execute(bureaucrats[i]);
            std::cout << "System : " << bureaucrats[i].getName() << " has executed the form.\n";
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
