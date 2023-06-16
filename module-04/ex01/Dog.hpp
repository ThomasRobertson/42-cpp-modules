#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		// Constructors
		Dog();
		Dog(const Dog &copy);

		// Destructor
		~Dog();

		// Operators
		Dog & operator=(const Dog &assign);
		void makeSound() const;

		void setIdeas(std::string idea);
		std::string getFirstIdea() const;
	private:
		static const std::string _className;
		Brain *_brain;
};

#endif