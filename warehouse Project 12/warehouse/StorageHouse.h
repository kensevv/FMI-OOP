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
	int totalCapacity;
	Vector<Section> warehouse;
public:
	StorageHouse();
	StorageHouse(const StorageHouse& other);
	StorageHouse& operator=(const StorageHouse& other);

	Vector<Section>& getWarehouse();
	
	void print();
	void loadWarehouse(const Vector<Product>& allProducts);
	void addProduct(const Product& product);
	void removeProduct(const String& name, int rQuantity);
	void clean();
};