#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	ICharacter* me = new Character("me");

	AMateria* tmp;
	//AMateria tmp1; does not work.

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("fire");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	std::cout << std::endl << "Assignment test : " << std::endl << std::endl;

	Character bob1("bob");
	Character me1("me"); 
	tmp = src->createMateria("ice");
	me1.equip(tmp);
	tmp = src->createMateria("cure");
	me1.equip(tmp);
	tmp = src->createMateria("fire");
	me1.equip(tmp);

	tmp = src->createMateria("cure");
	bob1.equip(tmp);

	me1.use(0, *bob);
	me1.use(1, *bob);
	me1.use(2, *bob);
	me1.use(3, *bob);

	std::cout << "Bob :" << std::endl;
	me1 = bob1;
	me1.use(0, *bob);
	me1.use(1, *bob);
	me1.use(2, *bob);
	me1.use(3, *bob);
	std::cout << "unequip() test : \n";
	bob1.unequip(0);
	bob1.use(0, me1);
	me1.use(0, *bob);
	me1.unequip(0);
	me1.unequip(1);
	me1.unequip(2);
	me1.unequip(3);
	me1.unequip(4);
	me1.use(0, *bob);
	me1.use(1, *bob);
	me1.use(2, *bob);
	me1.use(3, *bob);


	delete bob;
	delete me;
	delete src;
	return 0;
}