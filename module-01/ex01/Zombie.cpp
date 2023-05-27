#include "Zombie.hpp"

void Zombie::set_name(std::string name_input)
{
	name = name_input;
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name_input) : name(name_input)
{	
}

Zombie::Zombie() : name("<name>")
{	
}

Zombie::~Zombie()
{
	std::cout << name << ": Was I a good person ?" <<std::endl;
}
