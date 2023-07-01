#include "DiamondTrap.hpp"

const std::string DiamondTrap::_className = "DiamondTrap";

// Constructors
DiamondTrap::DiamondTrap() : ClapTrap("SEGFAULT 5000_clap_name")
{
	_name = "SEGFAULT 5000";
	_healthPoint = FragTrap::_healthPoint;
	_energyPoint = ScavTrap::_energyPoint;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "Default Constructor called of " << _className << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy._name + "_clap_name"), FragTrap(copy), ScavTrap(copy)
{
	_name = copy._name;
	std::cout << "Copy Constructor called of " << _className << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	_name = name;
	_healthPoint = FragTrap::_healthPoint;
	_energyPoint = ScavTrap::_energyPoint;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "Fields Constructor called of " << _className << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor called of " << "DiamondTrap" << std::endl;
}


// Operators
DiamondTrap & DiamondTrap::operator=(const DiamondTrap &assign)
{
	if (this != &assign)
	{
		_name = assign._name;
		_healthPoint = assign._healthPoint;
		_energyPoint = assign._energyPoint;
		_attackDamage = assign._attackDamage;
		ClapTrap::_name = assign.ClapTrap::_name;
	}
	return *this;
}


// Getters / Setters
std::string DiamondTrap::get_name() const
{
	return _name;
}

void DiamondTrap::status() const
{
	std::cout << _name << " has " << _healthPoint << " health point(s) left and " << _energyPoint
		<< " energy point(s) left." << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << _className << " : Hi I'm " << _name << " but my real friends call me "
		<< ClapTrap::_name << std::endl;
}
