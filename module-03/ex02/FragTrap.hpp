#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		// Constructors
		FragTrap();
		FragTrap(const FragTrap &copy);
		FragTrap(std::string name);
		
		// Destructor
		~FragTrap();
		
		// Operators
		FragTrap & operator=(const FragTrap &assign);
		
		// Getters / Setters
		std::string get_name() const;

		void status() const;
		void highFivesGuys(void);

	private:
		static const std::string _className;
};

#endif