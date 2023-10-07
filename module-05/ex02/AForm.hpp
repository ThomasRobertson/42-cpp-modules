#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat;

class AForm
{
public:
	// Constructors
	AForm(const AForm &copy);
	AForm(const std::string name, const unsigned int gradeRequiredToSign, const unsigned gradeRequiredToExecute);

	// Destructor
	virtual ~AForm();

	// Getters / Setters
	std::string getName() const;
	bool getIsSigned() const;
	unsigned int getGradeRequiredToSign() const;
	unsigned getGradeRequiredToExecute() const;

	// Exceptions
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
		virtual const char *what() const throw();
	};

	void beSigned(Bureaucrat const & bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;

protected:
	// Constructors
	AForm();

	// Operators
	AForm &operator=(const AForm &assign);

	bool checkGrade(unsigned int grade, unsigned int min = MIN_GRADE, unsigned int max = MAX_GRADE) const;
	bool canExecute(Bureaucrat const &b, AForm const &f) const;

private:
	const std::string _name;
	bool _isSigned;
	const unsigned int _gradeRequiredToSign;
	const unsigned _gradeRequiredToExecute;
};

// Stream operators
std::ostream &operator<<(std::ostream &stream, const AForm &object);

#endif
