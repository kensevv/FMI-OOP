// warehouse.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "StorageHouse.h"
#include <iostream>

bool isExpired(Date current, const Product& product)
{
	if (current > product.getExpiryDate()) return true;
	else return false;
}

void swap(Product & other, Product & another)
{
	Product temp = other;
	other = another;
	another = temp;
}

int main()
{
	Product kola;
	std::cout << kola;
}
