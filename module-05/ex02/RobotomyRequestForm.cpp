#include "RobotomyRequestForm.hpp"
#include <cstdlib>

// Constructors
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("RobotomyRequestForm", 72, 45)
{
	*this = copy;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	_target = target;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
}

// Operators
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
	if (this != &assign)
	{
		_target = assign._target;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	canExecute(executor, *this);
	std::cout << "Driiiiiiiiiiill" << std::endl;
	std::cout << "Robotomy operation on " << _target;
	if (rand() % 2)
		std::cout << " succeded." << std::endl;
	else
		std::cout << " failed, please try again." << std::endl;
}
