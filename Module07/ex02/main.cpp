#include <iostream>
#include <cstdlib>
#include <Array.hpp>

#define MAX_VAL 750
int	main(int, char**)
{
	std::cout << "----------SUBJECT'S MAIN----------" << std::endl;
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
	}
	std::cout << "----------FURTHER  TESTS----------" << std::endl;
	Array<float> numbers( 10 );
	Array<float> empty;
	Array<float> copy2;
	Array<float> zeros( 10 );
	srand(time(NULL));
	float	mirror[10];

	for ( int i = 0 ; i < 10 ; ++i ) {

		const float value = static_cast<float>( ( rand() % ( 100000 - 1000 + 1 ) ) + 1000 ) / static_cast<float>( ( rand() % ( 100 - 1 + 1 ) ) + 1 );
		numbers[i] = value;
		mirror[i] = value;
	}
	Array<float> copy1( numbers );
	copy2 = numbers;
	std::cout << "numbers.size() = " << numbers.size() << std::endl;
	std::cout << "empty.size() = " << empty.size() << std::endl;
	std::cout << "copy1.size() = " << copy1.size() << std::endl;
	std::cout << "copy2.size() = " << copy2.size() << std::endl;
	std::cout << "zeros.size() = " << zeros.size() << std::endl;
	std::cout << std::endl;
	for ( int i = 0 ; i < 10 ; ++i )
	{
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
		std::cout << "mirror[" << i << "] = " << mirror[i] << std::endl;
		std::cout << "copy1[" << i << "] = " << copy1[i] << std::endl;
		std::cout << "copy2[" << i << "] = " << copy2[i] << std::endl;
		std::cout << "zeros[" << i << "] = " << zeros[i] << std::endl;
		std::cout << std::endl;
	}
	copy2 = empty;
	copy2 = copy1;
	return 0;
}
