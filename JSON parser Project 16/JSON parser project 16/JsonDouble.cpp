#pragma once
#include "JsonDouble.h"

JsonDouble::JsonDouble()
{
}

JsonDouble::JsonDouble(const String& _jsontxt, const std::map<std::string, Json*> _elements, double _value)
	: Json(_jsontxt, _elements)
{
	this->value = _value;
}

JsonDouble::JsonDouble(double _value)
{
	this->value = _value;
}

JsonDouble::JsonDouble(const JsonDouble& other)
{
	copy(other);
}

JsonDouble& JsonDouble::operator=(const JsonDouble& other)
{
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}

double JsonDouble::getValue() const
{
	return this->value;
}

void JsonDouble::setValue(double value)
{
	this->value = value;
}

void JsonDouble::print()
{
	std::cout << this->value;
}

void JsonDouble::copy(const JsonDouble& other)
{
	Json::copy(other);
	this->value = other.value;
}