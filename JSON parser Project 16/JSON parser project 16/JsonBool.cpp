#pragma once
#include "JsonBool.h"

JsonBool::JsonBool()
{
}

JsonBool::JsonBool(const String& _jsontxt, const std::map<std::string, Json*> _elements, bool _value)
	:Json(_jsontxt, _elements)
{
	this->value = _value;
}

JsonBool::JsonBool(bool _value)
{
	this->value = _value;
}

JsonBool::JsonBool(const JsonBool& other)
{
	copy(other);
}

JsonBool& JsonBool::operator=(const JsonBool& other)
{
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}

bool JsonBool::getValue() const
{
	return this->value;
}

void JsonBool::setValue(bool value)
{
	this->value = value;
}

void JsonBool::print()
{
	std::cout << this->value ? "True" : "False";
}

void JsonBool::copy(const JsonBool& other)
{
	Json::copy(other);
	this->value = other.value;
}