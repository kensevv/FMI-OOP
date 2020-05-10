#pragma once
#include "Vector.cpp"
#include "String.h"
#include "Product.h"
#include "Date.h"

struct Cell {
	 int capacity;
	 Vector<Product> products;
	 Cell();
};
struct Shelf {
	 Vector<Cell> shelves;
	 Shelf();
}; 
struct Section {
	Vector<Shelf> sections;
	Section();
}; 

class StorageHouse
{
private:
	Vector<Section> warehouse;
	int totalCapacity;
	int nSectors;
	int nShelves;
	int nCells;
public:
	StorageHouse();
	StorageHouse(const StorageHouse& other);
	StorageHouse& operator=(const StorageHouse& other);
	void resetWH();

	int getnSectors() const;
	int getnShelves() const;
	int getnCells() const;

	Vector<Section>& getWarehouse();
	
	bool WHisFull();
	void loadWarehouse(Vector<Product>& allProducts);
	void addProduct(const Product& product);
	void removeProduct(const String& name, int rQuantity);
	void print();
	void clean(Vector<Product>& allProducts);
};