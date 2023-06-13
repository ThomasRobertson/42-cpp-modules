#include "WrongCat.hpp"

const std::string WrongCat::_className = "WrongCat";

// Constructors
WrongCat::WrongCat() : WrongAnimal::WrongAnimal("WrongCat")
{
	std::cout << "Default Constructor called of " << _className << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal::WrongAnimal(copy)
{
	std::cout << "Copy Constructor called of " << _className << std::endl;
}

// Destructor
WrongCat::~WrongCat()
{
	std::cout << "Destructor called of " << _className << std::endl;
}

// Operators
WrongCat & WrongCat::operator=(const WrongCat &assign)
{
	if (this != &assign)
	{
		_type = assign._type;
	}
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "I want to kill my owner." << std::endl;
}
