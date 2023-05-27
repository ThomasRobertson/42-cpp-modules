#include "HumanB.hpp"
#include <iostream>

void HumanB::attack()
{
	std::cout << name << " attacks with their ";
	if (negociator)
		std::cout << negociator->getType() << std::endl;
	else
		std::cout << "their bare hands" << std::endl;
}

HumanB::HumanB(std::string name_input) : name(name_input), negociator(NULL)
{
	
}

void HumanB::setWeapon(Weapon &new_weapon)
{
	negociator = &new_weapon;
}

// HumanA::HumanA(/* args */)
// {

// }

// HumanA::~HumanA()
// {

// }