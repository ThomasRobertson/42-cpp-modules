#include "ClapTrap.hpp"
#include <climits>

int main()
{
	{
		ClapTrap noName;

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
		noName.status();
	}
std::cout << std::endl;
	{
		ClapTrap bob("Bob");
		std::cout << std::endl;
		ClapTrap charly(bob);
		std::cout << std::endl;
		ClapTrap daryl;
		std::cout << std::endl;

		daryl = ClapTrap("Daryl");
		std::cout << std::endl;

		bob.status();
		std::cout << std::endl;
		charly.status();
		std::cout << std::endl;
		daryl.status();
		std::cout << std::endl;
	
		for (int i = 0; i != 10; i++)
			daryl.attack(bob.get_name());
		std::cout << std::endl;
		daryl.attack(charly.get_name());
		std::cout << std::endl;
		daryl.takeDamage(9);
		std::cout << std::endl;
		daryl.status();
		std::cout << std::endl;
		daryl.beRepaired(10);
		std::cout << std::endl;
		daryl.status();
	}
}