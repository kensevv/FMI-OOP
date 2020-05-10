#pragma once
#include<iostream>
struct Date
{
	int year;
	int month;
	int day;

	Date();
	Date(int newYear, int newMonth, int newDay);
	Date& operator=(const Date& other);

	bool operator==(const Date& other);
	bool operator<(const Date& other);
	bool operator>(const Date& other);

	friend std::ostream& operator<< (std::ostream& out, const Date& current);
	friend std::istream& operator>>(std::istream& in, Date& current);
};
	bool operator==(const Date& left, const Date& right);
	bool operator<(const Date& curr, const Date& other);
