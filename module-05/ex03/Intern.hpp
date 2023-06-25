#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

class Intern
{
	public:
		// Constructors
		Intern();
		Intern(const Intern &copy);
		
		// Destructor
		~Intern();
		
		// Operators
		Intern & operator=(const Intern &assign);
		
		AForm *shrubbery(std::string target);
		AForm *robotomy(std::string target);
		AForm *presidential(std::string target);
		AForm* makeForm(std::string formName, std::string target);
	private:
		
};

#endif