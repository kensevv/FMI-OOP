#include "Date.h"
#include<iostream>

Date::Date()
{
	this->year = 0;
	this->month = 0;
	this->day = 0;
}

Date::Date(int newYear, int newMonth, int newDay)
{
	this->year = newYear;
	this->month = newMonth;
	this->day = newDay;
}

Date& Date::operator=(const Date& other)
{
	this->year = other.year;
	this->month = other.month;
	this->day = other.day;
	
	return *this;
}

bool Date::operator<(const Date& other )
{

	if (this->year > other.year) return false;
	if (this->month > other.month) return false;
	if (this->day > other.day) return false;
	return true;
}

bool Date::operator>(const Date& other)
{
	if (this->year < other.year) return false;
	if (this->month < other.month) return false;
	if (this->day < other.day) return false;
	return true;
}

std::ostream& operator<<(std::ostream& out, const Date& current)
{
	out << current.year << "-" << current.month << "-" << current.day;
	return out;
}

std::istream& operator>>(std::istream& in, Date& current)
{
	std::cout << "enter date" << std::endl;
	
	std::cout << "Year: ";
	in >> current.year;
	
	std::cout << "Month: ";
	in >> current.month;

	std::cout << "Day: ";
	in >> current.day;

	return in;
}
