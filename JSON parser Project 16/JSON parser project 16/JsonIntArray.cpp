#include "JsonIntArray.h"

void JsonIntArray::copy(const JsonIntArray& other)
{
	Json::copy(other);
	this->value = other.value;
}

JsonIntArray::JsonIntArray()
{
}

JsonIntArray::JsonIntArray(std::vector<int> _value)
{
	this->value = _value;
}

JsonIntArray::JsonIntArray(const JsonIntArray& other)
{
	copy(other);
}

JsonIntArray& JsonIntArray::operator=(const JsonIntArray& other)
{
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}

std::vector<int> JsonIntArray::getValue() const
{
	return this->value;
}

void JsonIntArray::setValue(std::vector<int> _value)
{
	this->value = _value;
}

void JsonIntArray::print()
{
	for (int i = 0; i < value.size(); i++)
	{
		std::cout << value[i];
		if (i != value.size() - 1) std::cout << ", ";
	}
}
