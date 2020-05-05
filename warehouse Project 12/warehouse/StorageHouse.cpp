#include "StorageHouse.h"

StorageHouse::StorageHouse()
{
	for (int i = 0; i < 2; i++)
	{
		warehouse.push_back(Section());
	}
	totalCapacity = 4000;
}

StorageHouse::StorageHouse(const StorageHouse& other)
{
	this->totalCapacity = other.totalCapacity;
	this->warehouse = other.warehouse;
}

StorageHouse& StorageHouse::operator=(const StorageHouse& other)
{
	this->totalCapacity = other.totalCapacity;
	this->warehouse = other.warehouse;
	return *this;
}

Vector<Section>& StorageHouse::getWarehouse() 
{
	return this->warehouse;
}

void StorageHouse::print()
{
}

void StorageHouse::loadWarehouse(const Vector<Product>& allProducts)
{
}

void StorageHouse::addProduct(const Product& product)
{
}

void StorageHouse::removeProduct(const String& name, int rQuantity)
{
}

void StorageHouse::clean()
{
}


Cell::Cell()
{
	capacity = 50;
}

Shelf::Shelf()
{
	for (int i = 0; i < 10; i++)
	{
		shelves.push_back(Cell());
	}
}
Section::Section()
{
	for (int i = 0; i < 4; i++)
	{
		sections.push_back(Shelf());
	}
}