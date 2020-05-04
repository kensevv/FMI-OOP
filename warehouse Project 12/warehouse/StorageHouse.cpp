#include "StorageHouse.h"



StorageHouse::StorageHouse()
{
	//empty warehouse with:
	//2 sections, each has:
	//4 shelves, each has:
	//10 cells, each has 50 capacity
	Section section;
	warehouse.push_back(section).push_back(section);
	//total capacity: 4,000
	totalCapacity = 4000;
}
