#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

#include "Form.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

class Form;

class Bureaucrat
{
	public:
		// Constructors
		
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat(std::string name, unsigned int grade);
		
		// Destructor
		~Bureaucrat();
		
		// Operators
		Bureaucrat & operator=(const Bureaucrat &assign);
		
		// Getters / Setters
		unsigned int getGrade() const;
		std::string getName() const;

		// Exeptions
		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
		
		void increaseGrade();
		void decreaseGrade();
		void signForm(Form form) const;
	private:
		Bureaucrat();
		unsigned int _grade;
		const std::string _name;
		
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Bureaucrat &object);

#endif