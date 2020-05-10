#include "StorageHouse.h"

/* sklada e konstantno zadaden v programata
sustoi se ot 2 sekcii s po 4 shkafa vsqka ot koqto ima po 10 kletki
vsqka kletka moje da sudurja samo ednoimenni produkti, toest primerno 1 kletka ima samo Koka koli
vsqka kletka moje da sudurja samo 2 partidi ot suotvetniq produkt (vsqka partida e primerno s razlichni srokove na godnosti no sushtiq produkt

pri dobavqne na nov produkt v sklada se gleda dali ima veche sushtestvuvasht takuv, ako da i to ima ne poveche ot 1 partida produkta se dobavq
v protiven sluchay sklada ne priema 3ta partida ot produkta predi da prodade starite.
ako nqma produkt s takova ime produkta se dobavq v prazna kletka.
*/
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
	for (int section = 0; section < nSectors; section++)
	{
		for (int shelf = 0; shelf < nShelves; shelf++)
		{
			for (int cell = 0; cell < nCells; cell++)
			{
				warehouse[section].sections[shelf].shelves[cell].products.empty();
			}
		}
	}
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

void StorageHouse::addProduct(Product& product)
{
	if (!WHisFull())
	{
		for (int section = 0; section < nSectors; section++)
		{
			for (int shelf = 0; shelf < nShelves; shelf++)
			{
				for (int cell = 0; cell < nCells; cell++)
				{
					if (warehouse[section].sections[shelf].shelves[cell].products.getSize() == 1)
					{
						if (product.getName() == warehouse[section].sections[shelf].shelves[cell].products[0].getName())
						{
							if (product.getAddedToWh() == 0)
							{
								product.setAddedToWh(1);
								warehouse[section].sections[shelf].shelves[cell].products.push_back(product);
								std::cout << "Product has been added to - Section:" << section << " Shelf:" << shelf << " Cell" << cell << "." << std::endl;
							}
						}
					}
				}
			}
		}

		if (product.getAddedToWh() == 0)
		{
			for (int section = 0; section < nSectors; section++)
			{
				for (int shelf = 0; shelf < nShelves; shelf++)
				{
					for (int cell = 0; cell < nCells; cell++)
					{
						if (warehouse[section].sections[shelf].shelves[cell].products.getSize() == 0)
						{
							if (product.getAddedToWh() == 0)
							{
								product.setAddedToWh(1);
								warehouse[section].sections[shelf].shelves[cell].products.push_back(product);
								std::cout << "Product has been added to - Section:" << section << " Shelf:" << shelf << " Cell" << cell << "." << std::endl;
							}
						}
					}
				}
			}
		}
		if (product.getAddedToWh() == 0) std::cout << "There are already 2 batches from " << product.getName() << "." << std::endl;
	}
	else
	{
		std::cout << "ERROR: Your WareHouse is full" << std::endl;
	}
}

void StorageHouse::removeProduct(const String& name, int rQuantity, Vector<Product>& allProducts)
{
	for (int section = 0; section < nSectors; section++)
	{
		for (int shelf = 0; shelf < nShelves; shelf++)
		{
			for (int cell = 0; cell < nCells; cell++)
			{
				if (warehouse[section].sections[shelf].shelves[cell].products.getSize() != 0)
				{
					if (warehouse[section].sections[shelf].shelves[cell].products[0].getName() == name)
					{
						if (warehouse[section].sections[shelf].shelves[cell].products.getSize() == 1)
						{
							if (warehouse[section].sections[shelf].shelves[cell].products[0].getAvailableQuantity() - rQuantity <= 0)
							{
								std::cout << "You are trying to remove all or more than the available quantity." << std::endl
									<< "Do you want to remove all available quantity? (yes,no)" << std::endl
									<< ">";
								std::cin.get();
								String yesno;
								std::cin >> yesno;
								toLower(yesno);
								if (yesno == "yes")
								{
									warehouse[section].sections[shelf].shelves[cell].products.removeAtIndex(0);
									std::cout << section << " Shelf " << shelf << " Cell " << cell << std::endl
										<< name << " has been removed from the Warehouse" << std::endl;
									allProducts.removeElement(warehouse[section].sections[shelf].shelves[cell].products[0]);
								}
							}
							else 
							{
								warehouse[section].sections[shelf].shelves[cell].products[0].setAvailableQunatity
								(warehouse[section].sections[shelf].shelves[cell].products[0].getAvailableQuantity() - rQuantity);
								std::cout << rQuantity << " were removed from Section " << section << " Shelf " << shelf << " Cell " << cell << std::endl
									<< name << "'s batch with earlies expiry date." << std::endl
									<< "Remaining quantity: " << warehouse[section].sections[shelf].shelves[cell].products[0].getAvailableQuantity() << std::endl;
							}
						}
						else if (warehouse[section].sections[shelf].shelves[cell].products.getSize() == 2)
						{
							if (warehouse[section].sections[shelf].shelves[cell].products[0].getExpiryDate()
								< warehouse[section].sections[shelf].shelves[cell].products[1].getExpiryDate())
							{
								if (warehouse[section].sections[shelf].shelves[cell].products[0].getAvailableQuantity() - rQuantity <= 0)
								{
									std::cout << "You are trying to remove more than the Available Quantity" << std::endl
										<< "Do you want to remove all available quantity from the batch with earliest expiry date? (yes,no)" << std::endl
										<< ">";
									std::cin.get();
									String yesno;
									std::cin >> yesno;
									toLower(yesno);
									if (yesno == "yes")
									{
										warehouse[section].sections[shelf].shelves[cell].products.removeAtIndex(0);
										std::cout << section << " Shelf " << shelf << " Cell " << cell << std::endl
											<< name << "' batch has been removed from the Warehouse" << std::endl;
										allProducts.removeElement(warehouse[section].sections[shelf].shelves[cell].products[0]);
									}
								}
								else
								{
									warehouse[section].sections[shelf].shelves[cell].products[0].setAvailableQunatity
									(warehouse[section].sections[shelf].shelves[cell].products[0].getAvailableQuantity() - rQuantity);
									std::cout << rQuantity << " were removed from Section " << section << " Shelf " << shelf << " Cell " << cell << std::endl
										<< name << "'s batch with earlies expiry date." << std::endl
										<< "Remaining quantity: " << warehouse[section].sections[shelf].shelves[cell].products[0].getAvailableQuantity() << std::endl;
								}
							}
							else
							{
								if (warehouse[section].sections[shelf].shelves[cell].products[1].getAvailableQuantity() - rQuantity < 0)
								{
									std::cout << "You are trying to remove more than the Available Quantity" << std::endl
										<< "Do you want to remove all available quantity from the batch with earliest expiry date? (yes,no)" << std::endl
										<< ">";
									std::cin.get();
									String yesno;
									std::cin >> yesno;
									toLower(yesno);
									if (yesno == "yes")
									{
										warehouse[section].sections[shelf].shelves[cell].products.removeAtIndex(1);
										std::cout << section << " Shelf " << shelf << " Cell " << cell << std::endl
											<< name << "' batch has been removed from the Warehouse" << std::endl;
										allProducts.removeElement(warehouse[section].sections[shelf].shelves[cell].products[1]);
									}
								}
								else
								{
									warehouse[section].sections[shelf].shelves[cell].products[1].setAvailableQunatity
									(warehouse[section].sections[shelf].shelves[cell].products[1].getAvailableQuantity() - rQuantity);
									std::cout << rQuantity << " were removed from Section " << section << " Shelf " << shelf << " Cell " << cell << std::endl
										<< name << "'s batch with earlies expiry date." << std::endl
										<< "Remaining quantity: " << warehouse[section].sections[shelf].shelves[cell].products[1].getAvailableQuantity() << std::endl;
								}
							}
						}
					}
				}
			}
		}
	}
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