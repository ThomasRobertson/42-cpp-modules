#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		// Constructors
		ScavTrap();
		ScavTrap(const ScavTrap &copy);
		ScavTrap(std::string name);
		
		// Destructor
		~ScavTrap();
		
		// Operators
		ScavTrap & operator=(const ScavTrap &assign);
		
		// Getters / Setters
		std::string get_name() const;

		void attack(const std::string& target);
		void guardGate();
		void status() const;

	private:
		static const std::string _className;
		bool _guardGate;
};

#endif