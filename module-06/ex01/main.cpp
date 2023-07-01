#include "Serializer.hpp"

int main()
{
	Data new_data;
	std::cout << "new_data address : " << &new_data << "\n"
		<< "Data content : " << new_data.getPi() << " " << new_data.getSecret() << "\n";

	uintptr_t ptr = Serializer::serialize(&new_data);
	std::cout << "ptr : 0x" << std::hex << ptr << std::dec << " (" << ptr << ")\n";
	
	Data* data_ptr = Serializer::deserialize(ptr);
	std::cout << "data_ptr : " << data_ptr << "\n"
		<< "data_ptr content : " << data_ptr->getPi() << " " << data_ptr->getSecret() << "\n";
}
