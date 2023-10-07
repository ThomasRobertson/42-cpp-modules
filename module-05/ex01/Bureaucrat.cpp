#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat()
{
	_grade = MIN_GRADE;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	_grade = copy.getGrade();
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _grade(grade), _name(name)
{
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
}

// Operators
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &assign)
{
	_grade = assign.getGrade();
	return *this;
}

// Getters / Setters
unsigned int Bureaucrat::getGrade() const
{
	return _grade;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Bureaucrat &object)
{
	stream << object.getName() << ", bureaucrat grade " << object.getGrade() << "." << std::endl;
	return stream;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

void Bureaucrat::increaseGrade()
{
	if (_grade - 1 < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	--_grade;
}

void Bureaucrat::decreaseGrade()
{
	if (_grade + 1 > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	++_grade;
}

void Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " could't sign " << form.getName() << " because : " << e.what() << std::endl;
	}
	
}
