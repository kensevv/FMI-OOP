#include "Product.h"
#include <cstring>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void Product::copy(const Product & other)
{
	this->name = other.name;
	this->setType(other.Type);
	this->expiryDate = other.expiryDate;
	this->receiveDate = other.receiveDate;
	this->manufacturer = other.manufacturer;
	this->unit = other.unit;
	this->availableQuantity = other.availableQuantity;
	this->note = other.note;
}

Product::Product()
{
	setName("Default Name");
	setType(defaultType);
	setExpiryDate(1, 1, 2021);
	setReceiveDate(5, 4, 2020);
	setManufacturer("Default Manufacturer");
	setUnit(0);
	setAvailableQunatity(0);
	setNote("Default Note");
}

Product::Product(const Product& other)
{
	this->copy(other);
}

Product& Product::operator=(const Product& other)
{
	if (this != &other) this->copy(other);
	
	return *this;
}

Product::Product(const char* newName,productType newType ,Date newExpiryDate, Date newReceiveDate, const char* newManufacturer, bool newUnit, int newAvailableQuantity, const char* newNote)
	: name(nullptr), manufacturer(nullptr), note(nullptr)
{
	
	this->name = newName;
	this->setType(newType);
	setExpiryDate(newExpiryDate.day, newExpiryDate.month, newExpiryDate.year);
	setReceiveDate(newReceiveDate.day, newReceiveDate.month, newReceiveDate.year);
	this->manufacturer = newManufacturer;
	setUnit(newUnit);
	setAvailableQunatity(newAvailableQuantity);
	this->note = newNote;
}

void Product::setName(const char* newName)
{
	this->name = newName;
}

void Product::setName(const String& newName)
{
	this->name = newName;
}

void Product::setType(productType newType)
{
	switch (newType) 
	{
	case 0:
	{
		this->Type = defaultType;
		break;
	}
	case 1:
	{
		this->Type = food;
		break;
	}

	case 2:
	{
		this->Type = drinks;
		break;
	}

	case 3:
	{

		this->Type = alchohol;
		break;
	}
	case 4:
	{
		this->Type = parfumery;
		break;
	}

	case 5:
	{

		this->Type = householdGoods;
		break;
	}
	case 6:
	{

		this->Type = laundryGoods;
		break;
	}
	case 7:
	{

		this->Type = other;
		break;
	}
	default:
	{
		std::cout << "Wrong!";
		break;
	};
	}
}

void Product::setExpiryDate(int newYear, int newMonth, int newDay)
{
	this->expiryDate.year = newYear;
	this->expiryDate.month = newMonth;
	this->expiryDate.day = newDay;
}

void Product::setReceiveDate(int newYear, int newMonth, int newDay)
{
	this->receiveDate.year = newYear;
	this->receiveDate.month = newMonth;
	this->receiveDate.day = newDay;
}

void Product::setManufacturer(const char* newManufacturer)
{
	this->manufacturer = newManufacturer;
}

void Product::setManufacturer(const String& newManufacturer)
{
	this->manufacturer = newManufacturer;
}

void Product::setUnit(bool newUnit)
{
	this->unit = newUnit;
}

void Product::setAvailableQunatity(int newAvailableQuantity)
{
	this->availableQuantity = newAvailableQuantity;
}

void Product::setNote(const char* newNote)
{
	this->note = newNote;
}

void Product::setNote(const String& newNote)
{
	this->note = newNote;
}

const String& Product::getName() const
{
	return this->name;
}

productType Product::getType() const
{
	return this->Type;
}

const Date& Product::getExpiryDate() const
{
	return expiryDate;
}

const Date& Product::getReceiveDate() const
{
	return this-> receiveDate;
}

const String& Product::getManufacturer() const
{
	return this->manufacturer;
}

bool Product::getUnit() const
{
	return this->unit;
}

int Product::getAvailableQuantity() const
{
	return this->availableQuantity;
}

const String& Product::getNote() const
{
	return this->note;
}



std::ostream& operator<<(std::ostream& out, const Product& current)
{
	out << "Product name: " << current.name << endl
		<< "Product Type: " << current.Type << endl
		<< "expiryDate: " << current.expiryDate << endl
		<< "receiveDate: " << current.receiveDate << endl
		<< "Manufacturer: " << current.manufacturer << endl
		<< "Unit: ";
	if (current.unit == 0) out << "KGs" << endl;
	else if (current.unit == 1) out << "Liters" << endl;

	out << "AvailableQuantity: " << current.availableQuantity << endl
		<< "Note: " << current.note << endl;
	return out;
}

std::istream& operator>>(std::istream& in, Product& current) {
	cout << "Enter Product Name: ";
	
	//cin.get();
	//cin.getline(current.name, 128);
	String newName;
	cin >> newName;
	current.setName(newName);

	cout << "Enter Product Type (0-defaultType,1-food,2-drinks,3-alchohol,4-parfumery,5-householdGoods,6-laundryGoods,7-other)";
	int intType;
	in >> intType;
	switch (intType)
	{
	case 0:
	{
		current.Type = defaultType;
		break;
	}
	case 1:
	{
		current.Type = food;
		break;
	}

	case 2:
	{
		current.Type = drinks;
		break;
	}

	case 3:
	{

		current.Type = alchohol;
		break;
	}
	case 4:
	{
		current.Type = parfumery;
		break;
	}

	case 5:
	{

		current.Type = householdGoods;
		break;
	}
	case 6:
	{

		current.Type = laundryGoods;
		break;
	}
	case 7:
	{

		current.Type = other;
		break;
	}
	default:
	{
		std::cout << "Wrong!";
		break;
	};
	}
	
	cout << "Enter expiryDate below" << endl;
	cout << "Day: ";
	in >> current.expiryDate.day;
	cout << "Month: ";
	in >> current.expiryDate.month;
	cout << "Year: ";
	in >> current.expiryDate.year;

	cout << "Enter ReceiveDate below"<<endl;
	cout << "Day: ";
	in >> current.receiveDate.day;
	cout << "Month: ";
	in >> current.receiveDate.month;
	cout << "Year: ";
	in >> current.receiveDate.year;

	cout << "Enter manufacturer: ";
	String newManf;
	cin >> newManf;
	current.setManufacturer(newManf);

	cout << "Enter Units (0 - kg, 1 - liters) : ";
	in >> current.unit;

	cout << "Enter availableQuantity: ";
	in >> current.availableQuantity;

	cout << "Enter Note: ";
	//in.get();
	//in.getline(current.note, 300);
	String newNote;
	cin >> newNote;
	current.setNote(newNote);

	return in;
}
