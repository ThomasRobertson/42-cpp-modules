#include "Intern.hpp"

// Constructors
Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}


// Destructor
Intern::~Intern()
{
	std::cout << "No please don't kill me, I don't want to die !" << std::endl;
}


// Operators
Intern & Intern::operator=(const Intern &assign)
{
	(void) assign;
	return *this;
}

AForm *Intern::shrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::robotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}
AForm *Intern::presidential(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	std::string formsNames[] = {"presidential pardon", "robotomy request", "shruberry creaction"};
	AForm *forms[] = {Intern::presidential(target), Intern::robotomy(target), Intern::shrubbery(target)};

	for (size_t i = 0; i != sizeof formsNames / sizeof *formsNames; i++)
	{
		if (formName == formsNames[i])
		{
			std::cout << "Intern creates " << formsNames[i] << " form" << std::endl;
			return forms[i];
		}
	}
	std::cerr << "Sorry to bother you... I don't think this form exist" << std::endl;
	return (NULL);
}
