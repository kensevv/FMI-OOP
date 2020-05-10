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
	/*
	for (int i = 0; i < allProducts.getSize(); i++)
	{
		addProduct(allProducts[i]);
	}
	*/
	int productsNumber = 0;
	for (int section = 0; section < nSectors; section++) 
	{
		for (int shelf = 0; shelf < nShelves; shelf++) 
		{
			for (int cell = 0; cell < nCells; cell++) 
			{

				if (allProducts.getSize() != productsNumber && allProducts[productsNumber].getAddedToWh() == 0) // ako vsichki produkti ot allprodukts ne sa veche dobaveni i ako samiq produkt veche ne e dobaven v WH
				{
					warehouse[section].sections[shelf].shelves[cell].products.push_back(allProducts[productsNumber]);
					allProducts[productsNumber].setAddedToWh(1);
					
					for (int i = productsNumber + 1; i < allProducts.getSize() ; i++) //proverqvame za ednoimenni produkti koito mojem da slojim v sushtata kletka
					{
						if (allProducts[productsNumber].getName() == allProducts[i].getName()) // string cpp operator== const string const string
						{
							if (warehouse[section].sections[shelf].shelves[cell].products.getSize() != warehouse[section].sections[shelf].shelves[cell].capacity) // kletkata ima kapacitet za 2 partidi ot vseki produkt.
							{
								allProducts[i].setAddedToWh(1);
								warehouse[section].sections[shelf].shelves[cell].products.push_back(allProducts[i]);
							}
						}
					}
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

void StorageHouse::clean(Vector<Product>& allProducts)
{
	std::cout << "Input current date:";
	Date current;
	std::cin >> current;
	
	

	std::cout << "List of removed Products and their location in the WH:" << std::endl;
	for (int section = 0; section < nSectors; section++)
	{
		for (int shelf = 0; shelf < nShelves; shelf++)
		{
			for (int cell = 0; cell < nCells; cell++)
			{
				
				for (int j = 0; j < warehouse[section].sections[shelf].shelves[cell].products.getSize() ; j++)
				{
					if (warehouse[section].sections[shelf].shelves[cell].products[j].isExpired(current))
					{
						Product a(warehouse[section].sections[shelf].shelves[cell].products[j]);
						std::cout << "Section: " << section + 1 << "; Shelf: " << shelf + 1 << "; Cell: " << cell + 1 << " :" << std::endl;
						std::cout << a << std::endl;
						warehouse[section].sections[shelf].shelves[cell].products.removeAtIndex(j);
						
						allProducts.removeElement(a);
					}
				}				 
			}
		}
	}
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