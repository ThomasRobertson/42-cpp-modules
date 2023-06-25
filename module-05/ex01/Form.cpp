#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructors
Form::Form() : _isSigned(false), _gradeRequiredToSign(MAX_GRADE), _gradeRequiredToExecute(MIN_GRADE)
{
	checkGrade(_gradeRequiredToExecute);
	checkGrade(_gradeRequiredToSign);
}

Form::Form(const Form &copy) : _gradeRequiredToSign(copy._gradeRequiredToSign), _gradeRequiredToExecute(copy._gradeRequiredToExecute)
{
	*this = copy;
}

Form::Form(const std::string name, const unsigned int gradeRequiredToSign, const unsigned gradeRequiredToExecute) :
	_name(name), _isSigned(false), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExecute(gradeRequiredToExecute)
{
	checkGrade(_gradeRequiredToExecute);
	checkGrade(_gradeRequiredToSign);
}


// Destructor
Form::~Form()
{
}


// Operators
Form & Form::operator=(const Form &assign)
{
	_isSigned = assign.getIsSigned();
	return *this;
}


// Getters / Setters
std::string Form::getName() const
{
	return _name;
}
bool Form::getIsSigned() const
{
	return _isSigned;
}
unsigned int Form::getGradeRequiredToSign() const
{
	return _gradeRequiredToSign;
}
unsigned Form::getGradeRequiredToExecute() const
{
	return _gradeRequiredToExecute;
}


// Exceptions
const char * Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}
const char * Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}


// Stream operators
std::ostream & operator<<(std::ostream &stream, const Form &object)
{
	stream << "" << object.getName() << " form : \nGrade required to sign : " << object.getGradeRequiredToSign()
		<< "\nGrade required to execute : " << object.getGradeRequiredToExecute()
		<< "\nIs signed : " << object.getIsSigned() << std::endl;
	return stream;
}

bool Form::checkGrade(unsigned int grade, unsigned int min, unsigned int max)
{
	if (grade < max)
		throw Form::GradeTooHighException();
	else if (grade > min)
		throw Form::GradeTooLowException();
	else
		return true;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	checkGrade(bureaucrat.getGrade(), _gradeRequiredToSign);
	_isSigned = true;
}
