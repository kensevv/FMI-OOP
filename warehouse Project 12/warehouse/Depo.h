#pragma once
#include "Vector.cpp"
#include "Product.h"

struct Section
{
	struct Shelf
	{
		struct Cell
		{
			Vector<Product> products;
			bool full;
			int cellCapacity;
			Cell()
			{
				cellCapacity = 50;
				full = false;
			}
		}cell;
		Vector<Cell> cells;
		Shelf()
		{
			cells.push_back(cell).push_back(cell).push_back(cell).push_back(cell).push_back(cell).push_back(cell).push_back(cell).push_back(cell).push_back(cell).push_back(cell);
		}
	}shelf;
	Vector<Shelf> shelves;
	Section()
	{
		shelves.push_back(shelf).push_back(shelf).push_back(shelf).push_back(shelf);
	}
};