#include "Product.h"
#include <cstring>
#include <iostream>


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
	setExpiryDate(2021, 1, 1);
	setReceiveDate(2020, 4, 5);
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
{
	this->name = newName;
	this->setType(newType);
	this->expiryDate = newExpiryDate;
	this->receiveDate = newReceiveDate;
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

void Product::setType(int newType)
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
		//std::cout << "Wrong!";
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
		switch (current.Type)
		{
		case 0:
		{
			out << "(Default) ";
			break;
		}
		case 1:
		{
			out << "(Food) ";
			break;
		}

		case 2:
		{
			out << "(Drinks) ";
			break;
		}

		case 3:
		{
			out << "(Alchohol) ";
			break;
		}
		case 4:
		{
			out << "(Parfumery) ";
			break;
		}

		case 5:
		{

			out << "(Household Goods) ";
			break;
		}
		case 6:
		{

			out << "(Laundry Goods) ";
			break;
		}
		case 7:
		{

			out << "(Other) ";
			break;
		}
		default:
		{
			break;
		};
		}
		if (current.unit == 0) out << "(KGs)";
		else if (current.unit == 1) out << "(Liters)";
	out << ": " << current.name << " - " << current.manufacturer << std::endl
	    << "Quantity: " << current.availableQuantity << std::endl
		<< "expiryDate: " << current.expiryDate << ", receiveDate: " << current.receiveDate << std::endl
		<< "Note: " << current.note << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, Product& current) {
	std::cout << "Enter Product Name: ";
	String newName;
	std::cin >> newName;
	current.setName(newName);

	std::cout << "Enter Product Type (0-defaultType,1-food,2-drinks,3-alchohol,4-parfumery,5-householdGoods,6-laundryGoods,7-other)";
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
	
	std::cout << "Enter expiryDate below" << std::endl;
	std::cout << "Year: ";
	in >> current.expiryDate.year;
	std::cout << "Month: ";
	in >> current.expiryDate.month;
	std::cout << "Day: ";
	in >> current.expiryDate.day;
	

	std::cout << "Enter ReceiveDate below"<<std::endl;
	std::cout << "Year: ";
	in >> current.receiveDate.year;
	std::cout << "Month: ";
	in >> current.receiveDate.month;
	std::cout << "Day: ";
	in >> current.receiveDate.day;

	std::cout << "Enter manufacturer: ";
	String newManf;
	std::cin.get();
	std::cin >> newManf;
	current.setManufacturer(newManf);

	std::cout << "Enter Units (0 - kg, 1 - liters) : ";
	in >> current.unit;

	std::cout << "Enter availableQuantity: ";
	in >> current.availableQuantity;

	std::cout << "Enter Note: ";
	String newNote;
	std::cin.get();
	std::cin >> newNote;
	current.setNote(newNote);

	return in;
}
