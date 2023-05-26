#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie {
	public:
	void set_name(std::string name);
	void announce();
	Zombie();
	Zombie(std::string name);
	~Zombie();

	private:
	std::string name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
