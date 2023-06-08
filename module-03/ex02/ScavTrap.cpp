#include "ScavTrap.hpp"

const std::string ScavTrap::_className = "ScavTrap";

// Constructors
ScavTrap::ScavTrap() : _guardGate(false)
{
	_name = "SEGFAULT 4000";
	_healthPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
	std::cout << "Default Constructor called of " << _className << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy), _guardGate(copy._guardGate)
{
	std::cout << "Copy Constructor called of " << _className << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _guardGate(false)
{
	_healthPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
	std::cout << "Fields Constructor called of " << _className << std::endl;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called of " << "ScavTrap" << std::endl;
}


// Operators
ScavTrap & ScavTrap::operator=(const ScavTrap &assign)
{
	if (this != &assign)
	{
		_name = assign._name;
		_healthPoint = assign._healthPoint;
		_energyPoint = assign._energyPoint;
		_attackDamage = assign._attackDamage;
		_guardGate = assign._guardGate;
	}
	return *this;
}


// Getters / Setters
std::string ScavTrap::get_name() const
{
	return _name;
}

void ScavTrap::attack(const std::string& target)
{
	std::cout << _className << " : " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
	if (_healthPoint == 0)
		std::cout << "But that's a lie, it's dead." << std::endl;
	else if (_energyPoint == 0)
		std::cout << "But that's a lie, it's out of energy." << std::endl;
	else
		_energyPoint--;
}

void ScavTrap::guardGate()
{
	if (_energyPoint == 0 || _healthPoint == 0)
		std::cout << _className << " : " << _name << " cannot guard the gate!" << std::endl;
	else if (_guardGate == false)
	{
		std::cout << _className << " : " << _name << " is now guarding the gate!" << std::endl;
		_guardGate = true;
	}
	else
		std::cout << _className << " : " << _name << " was already guarding the gate!" << std::endl;
}

void ScavTrap::status() const
{
	std::cout << _name << " has " << _healthPoint << " health point(s) left and " << _energyPoint
		<< " energy point(s) left and ";
	if (_guardGate == true)
		std::cout << "is guarding the gate."<< std::endl;
	else
		std::cout << "is not guarding the gate."<< std::endl;
}
