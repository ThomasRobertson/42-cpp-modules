#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		// Constructors
		Cat();
		Cat(const Cat &copy);

		// Destructor
		~Cat();

		// Operators
		Cat & operator=(const Cat &assign);
		void makeSound() const;
	
		void setIdeas(std::string idea);
		std::string getFirstIdea() const;

	private:
		static const std::string _className;
		Brain *_brain;
};

#endif