#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
	std::string name;
	Weapon &negociator;

	public:
	void attack();
	HumanA(std::string name_input, Weapon &negociator_input);
		// ~HumanA();
};

#endif // HUMANA_HPP