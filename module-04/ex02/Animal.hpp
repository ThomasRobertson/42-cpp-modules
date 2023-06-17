#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	public:
		// Constructors
		Animal();
		Animal(const Animal &copy);
		Animal(std::string type);

		// Destructor
		//~Animal();
		virtual ~Animal();

		// Operators
		Animal & operator=(const Animal &assign);

		std::string getType() const;
		virtual void makeSound() const = 0;

	protected:
		std::string _type;

	private:
		static const std::string _className;
};

#endif