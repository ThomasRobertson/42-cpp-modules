#include "ClapTrap.hpp"
#include <climits>

int main()
{
	{
		ClapTrap noName;

		noName.status();
		noName.attack("it's shadow");
		noName.takeDamage(9);
		noName.status();
		noName.beRepaired(9);
		noName.status();
		noName.beRepaired(UINT_MAX);
		noName.status();
		noName.attack("it's shadow");
		noName.takeDamage(9);
		noName.beRepaired(9);
		noName.status();
	}

	{
		ClapTrap bob("Bob");
		ClapTrap charly(bob);
		ClapTrap daryl;

		daryl = ClapTrap("Daryl");

		bob.status();
		charly.status();
		daryl.status();
	
		for (int i = 0; i != 10; i++)
			daryl.attack(bob.get_name());
		daryl.attack(charly.get_name());
		daryl.takeDamage(9);
		daryl.status();
		daryl.beRepaired(10);
		daryl.status();
	}
}