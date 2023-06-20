#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "MateriaSource.hpp"

class Character : public ICharacter
{
	public:
		// Constructors
		Character();
		Character(const Character &copy);
		Character(std::string name);

		// Destructor
		~Character();

		// Operators
		Character & operator=(const Character &assign);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
	private:
		AMateria* _inventory[4];
		std::string _name;
};




#endif // CHARACTER_HPP