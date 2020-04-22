// warehouse.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "Product.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

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

/*void sortByReceiveDate(Product** products, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (products[j]->getReceiveDate().day > products[j + 1]->getReceiveDate().day)
			{
				swap(*products[j], *products[j + 1]);
			}
		}
	}
}*/


int main()
{

}
