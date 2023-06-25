#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructors
AForm::AForm() : _isSigned(false), _gradeRequiredToSign(MAX_GRADE), _gradeRequiredToExecute(MIN_GRADE)
{
	checkGrade(_gradeRequiredToExecute);
	checkGrade(_gradeRequiredToSign);
}

AForm::AForm(const AForm &copy) : _name(copy._name), _isSigned(false), _gradeRequiredToSign(copy._gradeRequiredToSign), _gradeRequiredToExecute(copy._gradeRequiredToExecute)
{
	*this = copy;
}

AForm::AForm(const std::string name, const unsigned int gradeRequiredToSign, const unsigned gradeRequiredToExecute) :
	_name(name), _isSigned(false), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExecute(gradeRequiredToExecute)
{
	checkGrade(_gradeRequiredToExecute);
	checkGrade(_gradeRequiredToSign);
}


// Destructor
AForm::~AForm()
{
}


// Operators
AForm & AForm::operator=(const AForm &assign)
{
	_isSigned = assign.getIsSigned();
	return *this;
}


// Getters / Setters
std::string AForm::getName() const
{
	return _name;
}
bool AForm::getIsSigned() const
{
	return _isSigned;
}
unsigned int AForm::getGradeRequiredToSign() const
{
	return _gradeRequiredToSign;
}
unsigned AForm::getGradeRequiredToExecute() const
{
	return _gradeRequiredToExecute;
}


// Exceptions
const char * AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}
const char * AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

const char * AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed.";
}


// Stream operators
std::ostream & operator<<(std::ostream &stream, const AForm &object)
{
	stream << "" << object.getName() << " Aform : \nGrade required to sign : " << object.getGradeRequiredToSign()
		<< "\nGrade required to execute : " << object.getGradeRequiredToExecute()
		<< "\nIs signed : " << object.getIsSigned() << std::endl;
	return stream;
}

bool AForm::checkGrade(unsigned int grade, unsigned int min, unsigned int max) const
{
	if (grade < max)
		throw AForm::GradeTooHighException();
	else if (grade > min)
		throw AForm::GradeTooLowException();
	else
		return true;
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	checkGrade(bureaucrat.getGrade(), _gradeRequiredToSign);
	_isSigned = true;
}

bool AForm::canExecute(Bureaucrat const &b, AForm const &f) const
{
	checkGrade(b.getGrade(), f.getGradeRequiredToExecute());
	if (!f.getIsSigned())
		throw AForm::FormNotSignedException();
	return true;
} 