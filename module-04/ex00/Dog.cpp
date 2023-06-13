#include "Dog.hpp"

const std::string Dog::_className = "Dog";

// Constructors
Dog::Dog() : Animal::Animal("Dog")
{
	std::cout << "Default Constructor called of " << _className << std::endl;
}

Dog::Dog(const Dog &copy) : Animal::Animal(copy)
{
	std::cout << "Copy Constructor called of " << _className << std::endl;
}

// Destructor
Dog::~Dog()
{
	std::cout << "Destructor called of " << _className << std::endl;
}

// Operators
Dog & Dog::operator=(const Dog &assign)
{
	if (this != &assign)
	{
		_type = assign._type;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Waf Waf" << std::endl;
}
