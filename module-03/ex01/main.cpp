#include "ScavTrap.hpp"
#include <climits>

int main()
{
	{
		ScavTrap noName;

		noName.status();
		std::cout << std::endl;
		noName.attack("it's shadow");
		std::cout << std::endl;
		noName.takeDamage(9);
		std::cout << std::endl;
		noName.status();
		std::cout << std::endl;
		noName.beRepaired(9);
		std::cout << std::endl;
		noName.guardGate();
		std::cout << std::endl;
		noName.status();
		std::cout << std::endl;
		noName.beRepaired(UINT_MAX);
		std::cout << std::endl;
		noName.status();
		std::cout << std::endl;
		noName.attack("it's shadow");
		std::cout << std::endl;
		noName.takeDamage(9);
		std::cout << std::endl;
		noName.beRepaired(9);
		std::cout << std::endl;
		noName.guardGate();
		std::cout << std::endl;
		noName.status();
	}
	std::cout << std::endl;
	{
		ScavTrap bob("Bob");
		std::cout << std::endl;
		ScavTrap charly(bob);
		std::cout << std::endl;
		ScavTrap daryl;
		std::cout << std::endl;

		daryl = ScavTrap("Daryl");
		std::cout << std::endl;

		bob.status();
		std::cout << std::endl;
		charly.status();
		std::cout << std::endl;
		daryl.status();
		std::cout << std::endl;
	
		for (int i = 0; i != 50; i++)
			daryl.attack(bob.get_name());
		std::cout << std::endl;
		daryl.attack(charly.get_name());
		std::cout << std::endl;
		daryl.takeDamage(99);
		std::cout << std::endl;
		daryl.status();
		std::cout << std::endl;
		daryl.beRepaired(100);
		std::cout << std::endl;
		daryl.guardGate();
		std::cout << std::endl;
		daryl.status();
		std::cout << std::endl;
	}
}