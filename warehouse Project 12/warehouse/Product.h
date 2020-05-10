#pragma once
#include <iostream>
#include "enumTypeProduct.h"
#include "Date.h"
#include "String.h"

class Product
{
private:
	String name;
	productType Type;
	Date expiryDate;
	Date receiveDate;
	String manufacturer;
	bool unit; // 0 - kg, 1 - l;
	int availableQuantity;
	String note;

	bool addedToWh;
	
	void copy(const Product & other);

public:
	Product();
	Product(const Product &other);
	Product& operator=(const Product &other);
	Product(const char* newName, productType newType, Date newExpiryDate, Date newReceiveDate, const char* newManufacturer, bool newUnit, int newAvailableQuantity, const char* newNote);

	
	void setName(const char* newName);
	void setName(const String & newName);
	void setType(productType newType);
	void setType(int newType);
	void setExpiryDate(int newYear, int newMonth, int newDay);
	void setReceiveDate(int newYear, int newMonth, int newDay);
	void setManufacturer(const char* newManufacturer);
	void setManufacturer(const String& newManufacturer);
	void setUnit(bool newUnit);
	void setAvailableQunatity(int newAvailableQuantity);
	void setNote(const char* newNote);
	void setNote(const String& newNote);

	const String& getName()const;
	productType getType()const;
	const Date& getExpiryDate() const;
	const Date& getReceiveDate()const;
	const String& getManufacturer()const;
	bool getUnit()const;
	int getAvailableQuantity()const;
	const String& getNote()const;

	void setAddedToWh(bool added);
	bool getAddedToWh() const;

	bool isExpired(Date current);


	friend std::ostream& operator<<(std::ostream& out, const Product& current);
	friend std::istream& operator>>(std::istream& in, Product& current);

	bool operator==(const Product& other) const;
};
