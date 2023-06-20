#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		// Constructors
		MateriaSource();
		MateriaSource(const MateriaSource &copy);

		// Destructor
		~MateriaSource();

		// Operators
		MateriaSource & operator=(const MateriaSource &assign);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
	private:
		AMateria* _knowledge_base[4];
};




#endif // MATERIALSOURCE_HPP