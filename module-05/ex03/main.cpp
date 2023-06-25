#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Intern unnamed;
	Bureaucrat higherBob("higherBob", 1);

	std::string formsNames[] = {"presidential pardon", "robotomy request", "shruberry creaction", "get me coffee"};
	for (size_t i = 0; i != sizeof formsNames / sizeof *formsNames; i++)
	{
		std::cout << std::endl << "--- " << formsNames[i] << " ---" << std::endl << std::endl;
		AForm *form = unnamed.makeForm(formsNames[i], "other_unnamed");
		if (form)
		{
			higherBob.signForm(*form);
			higherBob.executeForm(*form);
		}
		delete form;
	}	
}
