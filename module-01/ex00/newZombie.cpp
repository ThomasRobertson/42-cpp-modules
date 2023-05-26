#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie* new_zombie = new Zombie();
	new_zombie->set_name(name);
	new_zombie->announce();
	return new_zombie;
}
