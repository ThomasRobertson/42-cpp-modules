#include "Cat.hpp"

const std::string Cat::_className = "Cat";

// Constructors
Cat::Cat() : Animal::Animal("Cat")
{
	std::cout << "Default Constructor called of " << _className << std::endl;
}

Cat::Cat(const Cat &copy) : Animal::Animal(copy)
{
	std::cout << "Copy Constructor called of " << _className << std::endl;
}

// Destructor
Cat::~Cat()
{
	std::cout << "Destructor called of " << _className << std::endl;
}

// Operators
Cat & Cat::operator=(const Cat &assign)
{
	if (this != &assign)
	{
		_type = assign._type;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "I want to kill my owner." << std::endl;
}
