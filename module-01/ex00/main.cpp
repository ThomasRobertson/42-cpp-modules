#include "Zombie.hpp"

int main(int ac, char **av)
{
	std::string zombie1 = "Bob";
	std::string zombie2 = "Franck";	
	if (ac == 3)
	{
		std::string zombie1 = av[1];
		std::string zombie2 = av[2];
	}

	std::cout << "Creating on the stack :" << std::endl;
	Zombie* zombie_stack = newZombie(zombie1);

	std::cout << "Creating on the heap :" << std::endl;
	randomChump(zombie2);

	std::cout << "Cleaning up !" << std::endl;
	delete zombie_stack;

	return 0;
}
