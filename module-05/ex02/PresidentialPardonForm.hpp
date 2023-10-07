#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	// Constructors
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm(const std::string target);

	// Destructor
	~PresidentialPardonForm();

	void execute(Bureaucrat const &executor) const;

private:
	PresidentialPardonForm();
	// Operators
	PresidentialPardonForm &operator=(const PresidentialPardonForm &assign);
	std::string _target;
};

#endif // PresidentialPardonForm
