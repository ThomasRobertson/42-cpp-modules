#include "HumanA.hpp"
#include <iostream>

void HumanA::attack()
{
	std::cout << name << " attacks with their " << negociator.getType() << std::endl;
}

HumanA::HumanA(std::string name_input, Weapon &negociator_input) : name(name_input),
	negociator(negociator_input)
{

}

// HumanA::~HumanA()
// {

// }