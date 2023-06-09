#include "DiamondTrap.hpp"
#include <climits>

int main()
{
	{
		DiamondTrap noName;

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
		noName.takeDamage(99);
		std::cout << std::endl;
		noName.beRepaired(99);
		std::cout << std::endl;
		noName.highFivesGuys();
		std::cout << std::endl;
		noName.guardGate();
		std::cout << std::endl;
		noName.status();
	}
	std::cout << std::endl;
	{
		DiamondTrap bob("Bob");
		bob.whoAmI();
		std::cout << std::endl;

		DiamondTrap charly(bob);
		charly.whoAmI();
		std::cout << std::endl;

		DiamondTrap daryl;
		daryl.whoAmI();
		std::cout << std::endl;
		
		daryl = DiamondTrap("Daryl");
		daryl.whoAmI();
		std::cout << std::endl;

		bob.status();
		std::cout << std::endl;
		charly.status();
		std::cout << std::endl;
		daryl.status();
		std::cout << std::endl;
	
		for (int i = 0; i != 50; i++)
			bob.attack(daryl.get_name());
		std::cout << std::endl;
		bob.attack(daryl.get_name());
		std::cout << std::endl;
		bob.takeDamage(99);
		std::cout << std::endl;
		bob.status();
		std::cout << std::endl;
		bob.beRepaired(50);
		std::cout << std::endl;
		bob.highFivesGuys();
		std::cout << std::endl;
		
		bob.status();
		std::cout << std::endl;
		charly.status();
		std::cout << std::endl;
		daryl.status();
		std::cout << std::endl;
	}
}