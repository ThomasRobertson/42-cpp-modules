#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		// Constructors
		DiamondTrap();
		DiamondTrap(const DiamondTrap &copy);
		DiamondTrap(std::string name);
		
		// Destructor
		~DiamondTrap();
		
		// Operators
		//DiamondTrap & operator=(const DiamondTrap &assign);
		
		// Getters / Setters
		std::string get_name() const;

		void status() const;
		void whoAmI();

	private:
		static const std::string _className;
		std::string _name;
};

#endif