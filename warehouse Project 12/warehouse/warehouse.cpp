// warehouse.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "StorageHouse.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "enumTypeProduct.h"

void clearScreen();

void Menu();
void Open();
void Close();
void Save();
void SaveAs();
void Help();
void exit();
void fileWrite(std::ofstream& output);
void fileRead(std::ifstream& input);

void ProdManagement();
void Print();
void Add(Product & product);
void Remove(const String & rName, int rQuantity);
void Clean();
void getWHinfo();

bool Exit = false;

Vector<Product> allProducts;
StorageHouse warehouse;
String filename;
Date currentDate;

Vector<String> logs;
void printLogs();
char logsFile[9] = "logs.txt";
void readLogs();

int main()
{
	std::cout << "Warehouse management 1.0" << std::endl;
	std::cout << "Input current Date!" << std::endl;
	std::cin >> currentDate;
	Menu();
	do
	{
		if(filename[0] != 0) getWHinfo();

		char input;
		std::cout << "Enter (1) to open the Menu, Enter (2) for Product management." << std::endl
			<< ">";
		std::cin >> input;
		std::cin.get();
		if (input == '1')
		{
			Menu();
		}
		else if (input == '2')
		{
			if (filename[0] == 0) std::cout << "No information loaded. Open a file first." << std::endl;
			else ProdManagement();
		}
		else {
			std::cout << "Wrong input, try again!" << std::endl;
		}
	} while (!Exit);
	
}
void clearScreen()
{
	system("CLS");
	std::cout << "Warehouse management 1.0" << std::endl;
}
void Menu()
{
	std::cout << "Menu: Open, Close, Save, Save As, Help, Exit" << std::endl
		<< ">";

	do
	{
		String userInput;
		std::cin >> userInput;
		toLower(userInput);
		if (userInput == "open")
		{
			clearScreen();
			Open();
			break;
		}
		else if (userInput == "close")
		{
			clearScreen();
			Close();
			break;
		}
		else if (userInput == "save")
		{
			clearScreen();
			Save();
			break;
		}
		else if (userInput == "save as")
		{
			clearScreen();
			SaveAs();
			break;
		}
		else if (userInput == "help")
		{
			clearScreen();
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

void Open()
{
	if (filename[0] != 0)
	{
		std::cout << "Close First! There is already a file loaded into the memory." << std::endl;
	}
	else
	{
		
			std::ifstream input;
			std::cout << "Enter file name / path ( path / file_name.file_format )" << std::endl
				<< ">";
			char file[50];
			std::cin >> file;
			std::cin.get();
			input.open(file);
			if (input.is_open()) {
				fileRead(input);
				input.close();
				filename = file;
				warehouse.loadWarehouse(allProducts);
				std::cout << "All products from " << file << " were loaded and distributed in the warehouse. " << file << " has been closed." << std::endl;
			}
			else
			{
				std::cout << "ERROR! File with such path/name doesn't exist, try again." << std::endl;
				std::ofstream output(file);
				output.close();
				filename = file;
				std::cout << "New " << file << " has been created. " << file << " has been opened." << std::endl;
			}

			readLogs();
	}
}

void Close()
{
	if (filename[0] == 0)
	{
		std::cout << "Nothing to close. (No file opened/warehouse empty" << std::endl;
	}
	else
	{
		std::cout << "Successfully closed " << filename << ": memory resetted" << std::endl;
		filename.reset();
		allProducts.empty();
		warehouse.resetWH();
		logs.empty();
	}
}

void Save()
{
	if (filename[0] != 0)
	{
		char file[50];
		for (int i = 0; i < filename.lenght() + 1; i++)
		{
			file[i] = filename[i];
		}
		std::ofstream output;
		output.open(file);
		if (output.is_open())
		{
			fileWrite(output);
			std::cout << "Changes have been successfully saved to " << file << std::endl;
			filename.reset();
			allProducts.empty();
			warehouse.resetWH();
			logs.empty();
		}
		else
		{
			std::cout << "Error, changes could not been saved." << std::endl;
		}
	}
	else
	{
		std::cout << "There is no file opened / no products loaded into memory" << std::endl;
	}
}

void SaveAs()
{
	if (filename[0] != 0)
	{
		char file[50];
		std::cout << "Input new file name." << std::endl
			<< ">";
		std::cin >> file;
		std::ofstream output;
		output.open(file);
		if (output.is_open())
		{
			fileWrite(output);
			std::cout << "Changes have been successfully saved AS to file: " << file << std::endl;
			filename.reset();
			allProducts.empty();
			warehouse.resetWH();
			logs.empty();
		}
		else
		{
			std::cout << "Error, changes could not been saved." << std::endl;
		}
	}
	else
	{
		std::cout << "There is no file opened / no products loaded into memory" << std::endl;
	}
}

void Help()
{
	std::cout << "Help - commands and useful information!" << std::endl
		<< "User Menu details:" << std::endl << std::endl
		<< "OPEN: Loads the content of a file. If it does not exist, a new file will be created with the given name." << std::endl
		<< "All other commands can only be executed if a file is successfully loaded" << std::endl
		<< "Once the file is loaded, it closes it and the application no longer works with it unless the user requests to write back" << std::endl << std::endl
		<< "CLOSE: Closes the currently open document. " << std::endl
		<< "Closing clears the currently loaded information and the program cannot execute commands other than (Open)." << std::endl << std::endl
		<< "SAVE: Saves the changes made back to the same file from which the data was loaded." << std::endl << std::endl
		<< "SAVE AS: Records changes made to a new file, allowing the user to specify its path." << std::endl << std::endl
		<< "HELP: Displays brief information about the commands supported by the program." << std::endl << std::endl
		<< "EXIT: Exits the program." << std::endl << std::endl;
	std::cout << "Other user interface commands" << std::endl;
}

void exit()
{
	Exit = true;
	std::cout << "Exiting ..." << std::endl;
}
void fileWrite(std::ofstream& output)
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
void fileRead(std::ifstream& input)
{
	int numberProducts;
	input >> numberProducts;
	input.get();
	for (int i = 0; i < numberProducts; i++)
	{
		Product product;

		char readInfo[250];
		input.getline(readInfo, 250);
		//input.get();
		product.setName(readInfo);

		input.getline(readInfo, 250);
		//input.get();
		product.setManufacturer(readInfo);

		input.getline(readInfo, 250);
		//input.get();
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

		
		int year, month, day;
		input >> year;
		input.get();
		input >> month;
		input.get();
		input >> day;
		input.get();
		product.setReceiveDate(year, month, day);
		input >> day;
		input.get();
		input >> month;
		input.get();
		input >> day;
		input.get();
		product.setExpiryDate(year, month, day);

		allProducts.push_back(product);
	}
}

void ProdManagement()
{
	std::cout << "Product Management: Print, Add, Remove, Clean, Logs\n" << std::endl
		<< ">";
	do
	{
		String userInput;
		std::cin >> userInput;
		toLower(userInput);
		if (userInput == "print") {
			clearScreen();
			Print();
			break;
		}
		else if (userInput == "add") {
			Product newProduct;
			std::cin >> newProduct;
			clearScreen();
			Add(newProduct);
			break;
		}
		else if (userInput == "remove") {
			String rName;
			int rQuantity;
			std::cout << "Product name: ";
			std::cin >> rName;
			std::cout << "Quantity: ";
			std::cin >> rQuantity;

			clearScreen();
			Remove(rName, rQuantity);
			break;
		}
		else if (userInput == "clean") {
			clearScreen();
			Clean();
			break;
		}
		else if (userInput == "logs") {
			clearScreen();
			printLogs();
			break;
		}
		else {
			std::cout << "Wrong input, try again." << std::endl
				<< ">";
		}
	} while (true);
}

void Print()
{
	std::cout << std::endl << "List of all available products in the warehouse:" << std::endl << std::endl;
	warehouse.print();
}

void Add(Product & product)
{
	warehouse.addProduct(product);
	if (product.getAddedToWh() == 1) {
		std::cout << "Product has been successfully added to Warehouse." << std::endl;
		allProducts.push_back(product);

		//logs
		std::ofstream writeLog(logsFile, std::ios::app);
		if (writeLog.is_open())
		{
			writeLog << "[" << filename << "] " << currentDate << " Added " << product.getName() << " - " << product.getAvailableQuantity() << std::endl;
		}
		writeLog.close();
	}
}

void Remove(const String& rName, int rQuantity)
{
	warehouse.removeProduct(rName, rQuantity, allProducts);

	//logs
	std::ofstream writeLog(logsFile, std::ios::app);
	if (writeLog.is_open())
	{
		writeLog << "["<< filename <<"] " << currentDate << " Removed " << rName << " - " << rQuantity << std::endl;
	}
	writeLog.close();
}

void Clean()
{
	warehouse.clean(allProducts, currentDate);
	std::cout << "Your Warehouse has been cleaned from all expired products." << std::endl;

	//logs
	std::ofstream writeLog(logsFile, std::ios::app);
	if (writeLog.is_open())
	{
		writeLog << "[" << filename << "] "<< currentDate << " Cleaned" << std::endl;
	}
	writeLog.close();
}

void getWHinfo()
{
	std::cout << std::endl << "WH's total capacity is: " << warehouse.getTotalCapacity() << std::endl
		<< "Total products in WH: " << warehouse.getTotalWHQuantity() << std::endl;
	if (warehouse.getTotalExpiredProducts(currentDate) > 0)
	{
		std::cout << "There are " << warehouse.getTotalExpiredProducts(currentDate) << " expired products in your WH!" << std::endl
			<< "It is recommended you 'clean' your WH from all expired products." << std::endl;
	}
	else std::cout << "There are no expired products in WH." << std::endl;
}

void printLogs()
{
	for (int i = 0; i < logs.getSize(); i++)
	{
		std::cout << logs[i] << std::endl;
	}
}

void readLogs()
{
	std::ifstream readLogs(logsFile);
	if (readLogs.is_open())
	{
		while(!readLogs.eof())
		{
			char readInfo[250];
			readLogs.getline(readInfo, 250); 
			String log;
			log = readInfo;
			logs.push_back(log);
		}
		logs.removeAtIndex(logs.getSize()-1);
	}
	readLogs.close();
}
