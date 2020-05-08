#include "StorageHouse.h"

StorageHouse::StorageHouse()
{
	Section section;
	for (int i = 0; i < 2; i++)
	{
		warehouse.push_back(section);
	}
	totalCapacity = 4000;
	nSectors = 2;
	nShelves = 4;
	nCells = 10;
}

StorageHouse::StorageHouse(const StorageHouse& other)
{
	this->totalCapacity = other.totalCapacity;
	this->nSectors = other.nSectors;
	this->nShelves = other.nShelves;
	this->nCells = other.nCells;

	this->warehouse = other.warehouse; //?
}

StorageHouse& StorageHouse::operator=(const StorageHouse& other)
{
	if (this != &other)
	{
		this->totalCapacity = other.totalCapacity;
		this->nSectors = other.nSectors;
		this->nShelves = other.nShelves;
		this->nCells = other.nCells;

		this->warehouse = other.warehouse; // TODO test if it will work
	}
	return *this;
}

void StorageHouse::resetWH()
{
}

int StorageHouse::getnSectors() const
{
	return this->nSectors;
}

int StorageHouse::getnShelves() const
{
	return this->nShelves;
}

int StorageHouse::getnCells() const
{
	return this->nCells;
}

Vector<Section>& StorageHouse::getWarehouse() 
{
	return this->warehouse;
}

bool StorageHouse::WHisFull()
{
	for (int section = 0; section < nSectors; section++) 
	{
		for (int shelf = 0; shelf < nShelves; shelf++)
		{
			for (int cell = 0; cell < nCells; cell++)
			{
				if (warehouse[section].sections[shelf].shelves[cell].products.getSize() != 2)
				{
					return false;
				}
			}
		}
	}
	return true;
}

void StorageHouse::loadWarehouse(Vector<Product>& allProducts)
{
	int productsNumber = 0;
	for (int section = 0; section < nSectors; section++) 
	{
		for (int shelf = 0; shelf < nShelves; shelf++) 
		{
			for (int cell = 0; cell < nCells; cell++) 
			{
				//if (warehouse[section].sections[shelf].shelves[cell].products.getSize() == 0)
				//{
				//}
				if (allProducts.getSize() != productsNumber) {
					warehouse[section].sections[shelf].shelves[cell].products.push_back(allProducts[productsNumber]);
					productsNumber++;
				}
				
			}
		}
	}
}

void StorageHouse::addProduct(const Product& product)
{
}

void StorageHouse::removeProduct(const String& name, int rQuantity)
{
}

void StorageHouse::print()
{
	for (int section = 0; section < nSectors; section++)
	{
		for (int shelf = 0; shelf < nShelves; shelf++)
		{
			for (int cell = 0; cell < nCells; cell++) 
			{
				if (warehouse[section].sections[shelf].shelves[cell].products.getSize() != 0) {
					std::cout << "Section: " << section + 1 << "; Shelf: " << shelf + 1 << "; Cell: " << cell + 1 << " :" << std::endl;
					warehouse[section].sections[shelf].shelves[cell].products.print();
					std::cout << std::endl;
				}
			}
		}
	}
}

void StorageHouse::clean()
{
}


Cell::Cell()
{
	capacity = 2; // each cell can contain 2 products of same nametype. (maksimum dve partidi)
}

Shelf::Shelf()
{
	Cell cell;
	for (int i = 0; i < 10; i++) //nCells
	{
		shelves.push_back(cell);
	}
}
Section::Section()
{
	Shelf shelf;
	for (int i = 0; i < 4; i++) //nShelves
	{
		sections.push_back(shelf);
	}
}