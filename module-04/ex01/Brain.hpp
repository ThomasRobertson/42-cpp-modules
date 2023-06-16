#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	public:
		// Constructors
		Brain();
		Brain(const Brain &copy);

		// Destructor
		~Brain();

		// Operators
		Brain & operator=(const Brain &assign);
		void setIdeas(std::string idea);
		std::string getFirstIdea() const;

	private:
		static const std::string _className;
		std::string _ideas[100];
};

#endif