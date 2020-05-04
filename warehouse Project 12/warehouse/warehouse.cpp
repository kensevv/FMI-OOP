// warehouse.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "StorageHouse.h"
#include <iostream>
#include <fstream>

void Menu(Vector<Product>& allProducts, String & filename);
void Open(Vector<Product>& allProducts, String & filename);
void Close(Vector<Product>& allProducts, String& filename);
void Save(Vector<Product>& allProducts, String& filename);
void SaveAs(Vector<Product>& allProducts, String& filename);
void Help();
void exit();

bool isExpired(Date current, const Product& product);
void swap(Product& other, Product& another);

void fileWrite(std::ofstream& output ,Vector<Product> & allProducts);
void fileRead(std::ifstream& input, Vector<Product>& allProducts);

bool Exit = false;
int main()
{
	Vector<Product> allProducts;
	String filename;
	do
	{
		Menu(allProducts, filename);
	} while (!Exit);
	
}
void Menu(Vector<Product>& allProducts, String& filename)
{
	std::cout << "Menu: Open, Close, Save, Save As, Help, Exit" << std::endl
		<< ">";
	String userInput;
	do
	{
		std::cin >> userInput;
		toLower(userInput);
		if (userInput == "open")
		{
			Open(allProducts, filename);
			break;
		}
		else if (userInput == "close")
		{
			Close(allProducts,filename);
			break;
		}
		else if (userInput == "save")
		{
			Save(allProducts,filename);
			break;
		}
		else if (userInput == "save as")
		{
			SaveAs(allProducts,filename);
			break;
		}
		else if (userInput == "help")
		{
			Help();
			break;
		}
		else if (userInput == "exit")
		{
			exit();
			break;
		}
		else
		{
			std::cout << "Wrong input, try again." << std::endl
				<< ">";
		}

	} while (true);
	
}

void Open(Vector<Product>& allProducts, String& filename)
{
	if (filename[0] != 0)
	{
		std::cout << "Close First! There is already a file loaded into the memory." << std::endl;
		Menu(allProducts, filename);
	}
	else 
	{
		do
		{
			std::ifstream input;
			std::cout << "Enter file name / path" << std::endl
				<< ">";
			char file[50];
			std::cin >> file;
			std::cin.get();
			input.open(file);
			if (input.is_open()) {
				fileRead(input, allProducts);
				std::cout << "The date from " << file << " has been loaded to the memory." << std::endl;
				input.close();
				std::cout << file << " has been closed." << std::endl;
				filename = file;
				break;
			}
			else
			{
				std::cout << "ERROR! File with such path/name doesn't exist, try again." << std::endl;
			}
		} while (true);
		
	}
}

void Close(Vector<Product>& allProducts, String& filename)
{
	if (filename[0] == 0)
	{
		std::cout << "Nothing to close. (No file opened/warehouse empty" << std::endl;
	}
	else
	{
		filename.reset();
		allProducts.empty();
		std::cout << "Successfully closed " << filename << " : memory resetted" << std::endl;
	}
}

void Save(Vector<Product>& allProducts, String& filename)
{
}

void SaveAs(Vector<Product>& allProducts, String& filename)
{
}

void Help()
{
}

void exit()
{
	Exit = true;
	std::cout << "Exiting ..." << std::endl;
}
void fileWrite(std::ofstream& output, Vector<Product>& allProducts)
{
	output << allProducts.getSize() << std::endl;
	for (int i = 0; i < allProducts.getSize(); i++)
	{
		output << allProducts[i].getName() << std::endl;
		output << allProducts[i].getManufacturer() << std::endl;
		output << allProducts[i].getNote() << std::endl;

		output << allProducts[i].getAvailableQuantity() << std::endl;
		output << allProducts[i].getType() << std::endl;
		output << allProducts[i].getUnit() << std::endl;

		output << allProducts[i].getReceiveDate().year << std::endl;
		output << allProducts[i].getReceiveDate().month << std::endl;
		output << allProducts[i].getReceiveDate().day << std::endl;

		output << allProducts[i].getExpiryDate().year << std::endl;
		output << allProducts[i].getExpiryDate().month << std::endl;
		output << allProducts[i].getExpiryDate().day << std::endl;
	}
}
void fileRead(std::ifstream& input, Vector<Product>& allProducts)
{
	int numberProducts;
	input >> numberProducts;
	input.get();
	for (int i = 0; i < numberProducts; i++)
	{
		Product product;
		char readInfo[250];
		input >> readInfo;
		input.get();
		product.setName(readInfo);

		input >> readInfo;
		input.get();
		product.setManufacturer(readInfo);

		input >> readInfo;
		input.get();
		product.setNote(readInfo);

		int readQuantity;
		input >> readQuantity;
		input.get();
		product.setAvailableQunatity(readQuantity);

		int type;
		input >> type;
		input.get();
		product.setType(type);

		bool unit;
		input >> unit;
		input.get();
		product.setUnit(unit);

		Date newReceivedate;
		int dateNumber;
		input >> dateNumber;
		input.get();
		newReceivedate.year = dateNumber;
		input >> dateNumber;
		input.get();
		newReceivedate.month = dateNumber;
		input >> dateNumber;
		input.get();
		newReceivedate.day = dateNumber;
		product.setReceiveDate(newReceivedate.year, newReceivedate.month, newReceivedate.day);

		Date newExpiredate;
		input >> dateNumber;
		input.get();
		newExpiredate.year = dateNumber;
		input >> dateNumber;
		input.get();
		newExpiredate.month = dateNumber;
		input >> dateNumber;
		input.get();
		newExpiredate.day = dateNumber;
		product.setExpiryDate(newExpiredate.year, newExpiredate.month, newExpiredate.day);

		allProducts.push_back(product);
	}
}





bool isExpired(Date current, const Product& product)
{
	if (current > product.getExpiryDate()) return true;
	else return false;
}

void swap(Product& other, Product& another)
{
	Product temp = other;
	other = another;
	another = temp;
}