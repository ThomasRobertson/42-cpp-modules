#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm("ShrubberyCreationForm", 145, 137)
{
	*this = copy;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// Operators
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	if (this != &assign)
	{
		_target = assign._target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	canExecute(executor, *this);
	std::string filename = _target;

	filename += "_shrubbery";
	std::ofstream out_file(filename.c_str(), std::ios_base::out | std::ios_base::trunc);
	if (!out_file.is_open())
	{
		std::cerr << "Could not execute order Shrubbery : file not created." << std::endl;
		return;
	}

	out_file << "   *\n"
			 << "  *** \n"
			 << " ***** \n"
			 << "   *" << std::endl;
}
