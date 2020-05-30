#include "JsonString.h"

void JsonString::copy(const JsonString& other)
{
	Json::copy(other);
	this->value = other.value;
}

JsonString::JsonString()
{
}

JsonString::JsonString(const std::string& _jsontxt, const std::map<std::string, Json*> _elements, std::string _value)
	: Json(_jsontxt, _elements)
{
		this->value = _value;
}

JsonString::JsonString(std::string _value)
{
	this->value = _value;
}

JsonString::JsonString(const JsonString& other)
{
	copy(other);
}

JsonString& JsonString::operator=(const JsonString& other)
{
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}

const std::string& JsonString::getValue() const
{
	return this->value;
}

void JsonString::setValue(std::string _value)
{
	this->value = _value;
}

void JsonString::print()
{
	std::cout << this->value;
}
