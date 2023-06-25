#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm("PresidentialPardonForm", 25, 5)
{
	*this = copy;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	_target = target;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
}

// Operators
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
	if (this != &assign)
	{
		_target = assign._target;
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	canExecute(executor, *this);
	std::cout << _target << " was pardon by Zaphod Beeblebrox !" << std::endl;
}
