#pragma once
#include "JsonInt.h"

JsonInt::JsonInt()
{
}

JsonInt::JsonInt(const String& _jsontxt, const std::map<std::string, Json*> _elements, int _value)
	: Json(_jsontxt, _elements)
{
	this->value = _value;
}

JsonInt::JsonInt(const JsonInt& other)
{
	copy(other);
}

JsonInt& JsonInt::operator=(const JsonInt& other)
{
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}

int JsonInt::getValue() const
{
	return this->value;
}

void JsonInt::setValue(int value)
{
	this->value = value;
}

void JsonInt::print()
{
	std::cout << this->value;
}

void JsonInt::copy(const JsonInt& other)
{
	Json::copy(other);
	this->value = other.value;
}
