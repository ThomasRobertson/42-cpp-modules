#include "ClapTrap.hpp"

const std::string ClapTrap::_className = "ClapTrap";

// Constructors
ClapTrap::ClapTrap() : _name("SEGFAULT 3000") ,_healthPoint(10) ,_energyPoint(10) ,_attackDamage(0)
{
	std::cout << "Default Constructor called of " << _className << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) : _name(copy._name) ,_healthPoint(copy._healthPoint) ,_energyPoint(copy._energyPoint) ,_attackDamage(copy._attackDamage)
{
	std::cout << "Copy Constructor called of " << _className << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _healthPoint(10) ,_energyPoint(10) ,_attackDamage(0)
{
	std::cout << "Fields Constructor called of " << _className << std::endl;
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called of " << _className << std::endl;
}


// Operators
ClapTrap & ClapTrap::operator=(const ClapTrap &assign)
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
std::string ClapTrap::get_name() const
{
	return _name;
}
unsigned int ClapTrap::get_healthPoint() const
{
	return _healthPoint;
}
unsigned int ClapTrap::get_energyPoint() const
{
	return _energyPoint;
}
unsigned int ClapTrap::get_attackDamage() const
{
	return _attackDamage;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << _className << " : " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
	if (_healthPoint == 0)
		std::cout << "But that's a lie, it's dead." << std::endl << std::endl;
	else if (_energyPoint == 0)
		std::cout << "But that's a lie, it's out of energy." << std::endl << std::endl;
	else
	{
		std::cout << std::endl;
		_energyPoint--;
	}
		
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > _healthPoint)
		amount = _healthPoint;
	std::cout << _className << " : " << _name << " is attacked "
			<< ", taking " << amount << " points of damage!" << std::endl;

	if (_healthPoint == 0)
		std::cout << "Oh wait, it was already dead..." << std::endl << std::endl;
	else
	{
		_healthPoint -= amount;
		std::cout << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int newHealthPoint = _healthPoint + amount;

	std::cout << _className << " : " << _name << " is repaired "
		<< ", gaining " << amount << " points of health!" << std::endl;

	if (_healthPoint == 0)
		std::cout << "But that's a lie, it was already dead." << std::endl << std::endl;
	else if (_energyPoint == 0)
		std::cout << "But that's a lie, it's out of energy." << std::endl << std::endl;
	else if (newHealthPoint < _healthPoint || newHealthPoint < amount)
	{
		std::cout << "Oh no... Gaining to much health... Cannot continue..." << std::endl
			<< _name << " died..." << std::endl << std::endl;
		_healthPoint = 0;
	}
	else
	{
		_healthPoint += amount;
		_energyPoint--;
		std::cout << std::endl;
	}
}

void ClapTrap::status() const
{
	std::cout << _name << " has " << _healthPoint << " health point(s) left and " << _energyPoint
		<< " energy point(s) left." << std::endl << std::endl;
}
