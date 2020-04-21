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
void sortByReceiveDate(Product** products, int size)
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
}

int main()
{
	
	Product testA, testB; // default constructor test
	
	//operators test << >> =
	cout << "cin >> testA;" << endl;
	cin >> testA; 
	cout << " cout << testA; " << endl << testA << endl;
	testB = testA;
	cout << " cout << testB; " << endl << testB << endl;
	cout << endl;
	Date testExpiryDate;
	cout << "testExpiryDate :";
	cin >> testExpiryDate;
	Date testReceiveDate(7, 4, 2020);
	// date: operator <  test:
	cout << "textexpirydate: " << testExpiryDate << endl;
	cout << "testreceivedate: " << testReceiveDate << endl;
	cout << "(testExpiryDate < testReceiveDate): " << (testExpiryDate < testReceiveDate) << endl;
	cout << endl;
	Product cola("Cola", drinks, testExpiryDate, testReceiveDate, "Derby", 1, 100, "Non-Alchohol Drink - Coca-Cola" );
	cout << " cout << cola; " << endl << cola << endl;
	Date today(7, 4, 2020);
	cout << "Date today : " << today << endl;
	cout << "is Cola expred? : " << isExpired(today, cola) << endl;
	
	cout << endl;
	
	cout << "array of products:";
	const int SIZE = 2;
	//Product products[SIZE];
	Product* products = new Product[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		cin >> products[i];
	}
	cout << endl << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << products[i];
	}
	cout << endl;
	
	cout<< "sortbyDate function test";
	sortByReceiveDate(&products, SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		cout << products[i];
	}
	delete[] products;
}
