#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		// Constructors
		Cure();
		Cure(const Cure &copy);
		
		// Destructor
		~Cure();
		
		// Operators
		Cure & operator=(const Cure &assign);

		AMateria* clone() const;
		void use(ICharacter& target);
	private:
		
};

#endif