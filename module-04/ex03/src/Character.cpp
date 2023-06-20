#include "Character.hpp"

Character::Character()
{
	for (size_t i = 0; i != 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	for (size_t i = 0; i != 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &copy)
{
	*this = copy;
}

Character & Character::operator=(const Character &assign)
{
	if (this != &assign)
	{
		for (size_t i = 0; i != 4; i++)
		{
			delete _inventory[i];
			if (assign._inventory[i])
				_inventory[i] = assign._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
		_name = assign._name;
	}
	return *this;
}

Character::~Character()
{
	for (size_t i = 0; i != 4; i++)
		delete _inventory[i];
}

std::string const & Character::getName() const
{
	return(_name);
}

void Character::equip(AMateria* m)
{
	for(size_t i = 0; i != 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 4)
		_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
}
