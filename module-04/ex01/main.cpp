#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const unsigned size_array = 10;
	Animal* array[size_array];

	for (unsigned i = 0; i != size_array / 2; i++)
	{
		array[i] = new Dog();
	}

	for (unsigned i = size_array / 2; i != size_array; i++)
	{
		array[i] = new Cat();
	}

	for (unsigned i = 0; i != size_array; i++)
	{
		delete array[i];
	}

	Dog test;
	test.setIdeas("Dog's temp ideas.");
	{
		Dog test_tmp(test);
		test_tmp.setIdeas("Dog's ideas.");
		std::cout << test_tmp.getFirstIdea() << std::endl;
	}
	std::cout << test.getFirstIdea() << std::endl;
	return 0;
}

// int main()
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j;//should not create a leak
// 	delete i;
// 	return 0;
// }
