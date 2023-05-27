#ifndef WEAPON_H
# define WEAPON_H

#include <string>

class Weapon
{
	private:
		std::string type;
	public:
		const std::string& getType();
		void setType(std::string new_type);
		Weapon(std::string weapon_type);
		Weapon();
		// ~Weapon();
};

#endif // WEAPON_H