#ifndef WRONGWrongANIMAL_HPP
# define WRONGWrongANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	public:
		// Constructors
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal(std::string type);

		// Destructor
		//~WrongAnimal();
		~WrongAnimal();

		// Operators
		WrongAnimal & operator=(const WrongAnimal &assign);

		std::string getType() const;
		void makeSound() const;

	protected:
		std::string _type;

	private:
		static const std::string _className;
};

#endif