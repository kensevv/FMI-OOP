#pragma once
#include "Vector.cpp"
#include "String.h"
#include "Product.h"
#include "Date.h"

class StorageHouse
{
public:
	Vector<Product> products;
	int storageCapacity;

	StorageHouse();

	void outputStorageHouse();
	void inputStorageHouse();

	void printProducts();
	void add();
	void addExisting();
	void remove();
	void clean();

	void setProductLoc(Product& product);
};