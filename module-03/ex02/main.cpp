#include "FragTrap.hpp"
#include <climits>

int main()
{
	{
		FragTrap noName;

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
		noName.highFivesGuys();
		std::cout << std::endl;
		noName.status();
		std::cout << std::endl;
		noName.beRepaired(UINT_MAX);
		std::cout << std::endl;
		noName.status();
		std::cout << std::endl;
		noName.attack("it's shadow");
		std::cout << std::endl;
		noName.takeDamage(99);
		std::cout << std::endl;
		noName.beRepaired(99);
		std::cout << std::endl;
		noName.highFivesGuys();
		std::cout << std::endl;
		noName.status();
	}
	std::cout << std::endl;
	{
		FragTrap bob("Bob");
		std::cout << std::endl;
		FragTrap charly(bob);
		std::cout << std::endl;
		FragTrap daryl;
		std::cout << std::endl;

		daryl = FragTrap("Daryl");
		std::cout << std::endl;

		bob.status();
		std::cout << std::endl;
		charly.status();
		std::cout << std::endl;
		daryl.status();
		std::cout << std::endl;
	
		for (int i = 0; i != 100; i++)
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
		daryl.highFivesGuys();
		std::cout << std::endl;
		daryl.status();
		std::cout << std::endl;
	}
}