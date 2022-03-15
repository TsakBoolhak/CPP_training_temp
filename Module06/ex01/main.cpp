#include "Data.hpp"
#include <stdint.h>

uintptr_t	serialize(Data* ptr) {

	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		deserialize(uintptr_t raw) {

	return reinterpret_cast<Data *>(raw);
}

int	main()
{
	Data	data1;
	Data	data2( 3, 3.333f, "threeeeeeeeeee" );
	Data	data3( data1 );
	Data	data4;

	data4 = data2;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << data1 << std::endl;
	std::cout << data2 << std::endl;
	std::cout << data3 << std::endl;
	std::cout << data4 << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << std::endl;

	Data	*dataPtr1 = &data2;
	uintptr_t	ptrRawValue = serialize( &data2 );
	Data	*dataPtr2 = deserialize( ptrRawValue );

	std::cout << "dataPtr1 is ";
	if ( dataPtr1 != dataPtr2 )
		std::cout << "not ";
	std::cout << "equal to dataPtr2" << std::endl;
	
	std::cout << *dataPtr2 << std::endl;
	return 0;
}
