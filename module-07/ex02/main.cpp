#include <iostream>
#include <Array.hpp>
#include <cassert>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int mirror[MAX_VAL];

	{
		Array<int> numbers_empty;
		try
    	{
    	    numbers_empty[0] = 0;
    	}
    	catch(const std::exception& e)
    	{
    	    std::cerr << "Empty array : " <<e.what() << '\n';
    	}
		assert(numbers_empty.size() == 0);
	}
	// Testing size
	assert(numbers.size() == MAX_VAL);

	// Testing unintialized array
    for (size_t i = 0; i < numbers.size(); i++)
    {
        assert(numbers[i] == 0);
    }

	// Filling arrays with const
    srand(time(NULL));
    for (size_t i = 0; i < numbers.size(); i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    for (size_t i = 0; i < numbers.size(); i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    // Testing scope
	numbers[0] = 0;
    {
		
        Array<int> tmp = numbers;
        Array<int> test(tmp);
		tmp[0] = 1;
		assert(numbers[0] == 0);
		test[0] = 2;
		assert(numbers[0] == 0);
    }
	assert(numbers[0] == 0);

	// Testing out of range
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "numbers[-2] : " << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "numbers[MAX_VAL] : " << e.what() << '\n';
    }

    for (size_t i = 0; i < numbers.size(); i++)
    {
        numbers[i] = rand();
    }
	const int i = numbers[0];
	if (i != numbers[0])
		std::cout << "Not the same number\n";
    return 0;
}