#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i != 4; i++)
	{
		_knowledge_base[i] = NULL;
	}	
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	*this = copy;
}

MateriaSource & MateriaSource::operator=(const MateriaSource &assign)
{
	if (this != &assign)
	{
		for (size_t i = 0; i != 4; i++)
		{
			delete _knowledge_base[i];
			_knowledge_base[i] = assign._knowledge_base[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i != 4; i++)
		delete _knowledge_base[i];
}

void MateriaSource::learnMateria(AMateria* src)
{
	for (size_t i = 0; i != 4; i++)
	{
		if (_knowledge_base[i] != NULL)
			continue ;
		_knowledge_base[i] = src;
		break ;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i != 4; i++)
	{
		if (_knowledge_base[i] == NULL || _knowledge_base[i]->getType() != type)
			continue ;
		return _knowledge_base[i]->clone();
	}
	return NULL;
}
