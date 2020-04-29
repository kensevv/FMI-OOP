#include "StorageHouse.h"

StorageHouse::StorageHouse()
{
	this->storageCapacity = 5000;
}

void StorageHouse::printProducts()
{
	for (size_t i = 0; i < products.getSize(); i++)
	{
		std::cout << products[i] << std::endl;
	}
}
