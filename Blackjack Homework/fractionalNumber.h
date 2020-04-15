#pragma once
#include<iostream>

struct fractionalNumber
{
public:
	int numerator;
	int denominator;

	
	friend std::ostream& operator<<(std::ostream& out, const fractionalNumber& fracNumber)
	{
		out << fracNumber.numerator << "/" << fracNumber.denominator;
		return out;
	}
	
};
