#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	// Constructors
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm(const std::string target);

	// Destructor
	~ShrubberyCreationForm();

	void execute(Bureaucrat const &executor) const;

private:
	ShrubberyCreationForm();
	// Operators
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &assign);
	std::string _target;
};

#endif // ShrubberyCreationForm
