#pragma once
#include "Vector.cpp"
#include "String.h"
#include "Product.h"
#include "Date.h"
#include "Depo.h"

class StorageHouse
{
private:
	int totalCapacity;
	Vector<Section> warehouse;
public:
	StorageHouse();
};

