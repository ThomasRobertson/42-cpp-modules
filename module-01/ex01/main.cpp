#include "Zombie.hpp"

int main()
{
	std::string zombie1 = "Bob";
	zombie1 = zombie1 + "Toto";
	const int size[] = {1, 2, 4, 8};

	Zombie* new_horde;
	//std::cout << sizeof(int) << sizeof(size) << sizeof (*size) << std::endl;
	for (long unsigned int i = 0; i < (sizeof(size) / sizeof(*size)); i++)
	{
		new_horde = zombieHorde(size[i], zombie1);
		delete[] new_horde;
		
	}
	
	return 0;
}
