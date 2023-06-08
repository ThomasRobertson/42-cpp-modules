#include "FragTrap.hpp"

const std::string FragTrap::_className = "FragTrap";

// Constructors
FragTrap::FragTrap()
{
	_name = "SEGFAULT 5000";
	_healthPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
	std::cout << "Default Constructor called of " << _className << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "Copy Constructor called of " << _className << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_healthPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
	std::cout << "Fields Constructor called of " << _className << std::endl;
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "Destructor called of " << "FragTrap" << std::endl;
}


// Operators
FragTrap & FragTrap::operator=(const FragTrap &assign)
{
	if (this != &assign)
	{
		_name = assign._name;
		_healthPoint = assign._healthPoint;
		_energyPoint = assign._energyPoint;
		_attackDamage = assign._attackDamage;
	}
	return *this;
}


// Getters / Setters
std::string FragTrap::get_name() const
{
	return _name;
}

void FragTrap::status() const
{
	std::cout << _name << " has " << _healthPoint << " health point(s) left and " << _energyPoint
		<< " energy point(s) left." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << _name << " is requesting a high fives !" << std::endl;
	if (_energyPoint == 0)
		std::cout << "Request failed... no more... batteries..." << std::endl;
	else if (_healthPoint == 0)
		std::cout << "[ERROR 408] Request time out." << std::endl;
	else
		std::cout << "Request granted, come here my fellow CrapTraps !" << std::endl;
}
