#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

#include "Bureaucrat.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat;

class Form
{
	public:
		// Constructors
		Form(const Form &copy);
		Form(const std::string name, const unsigned int gradeRequiredToSign, const unsigned gradeRequiredToExecute);
		
		// Destructor
		~Form();
		
		// Getters / Setters
		std::string getName() const;
		bool getIsSigned() const;
		unsigned int getGradeRequiredToSign() const;
		unsigned getGradeRequiredToExecute() const;
		
		// Exceptions
		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		};

		void beSigned(Bureaucrat const & bureaucrat);
		
	private:
		// Constructors
		Form();

		// Operators
		Form & operator=(const Form &assign);

		const std::string _name;
		bool _isSigned;
		const unsigned int _gradeRequiredToSign;
		const unsigned _gradeRequiredToExecute;

		bool checkGrade(unsigned int grade, unsigned int min=MIN_GRADE, unsigned int max=MAX_GRADE);
		
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Form &object);

#endif