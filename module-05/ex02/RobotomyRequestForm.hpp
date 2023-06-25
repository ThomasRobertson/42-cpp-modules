#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	// Constructors
	
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	RobotomyRequestForm(const std::string target);

	// Destructor
	~RobotomyRequestForm();

	void execute(Bureaucrat const &executor) const;

private:
	RobotomyRequestForm();
	// Operators
	RobotomyRequestForm &operator=(const RobotomyRequestForm &assign);
	std::string _target;
};

#endif // RobotomyRequestForm