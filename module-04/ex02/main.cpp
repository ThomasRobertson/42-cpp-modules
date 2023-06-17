#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// Animal test1; //not working
	Animal *test2;
	test2 = new Dog;
	test2->makeSound();
	delete test2;
}
