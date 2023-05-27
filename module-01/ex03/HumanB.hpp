#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
	std::string name;
	Weapon *negociator;

	public:
	void attack();
	void setWeapon(Weapon &new_weapon);
	HumanB(std::string name_input);
		// ~HumanB();
};

#endif // HUMANB_HPP