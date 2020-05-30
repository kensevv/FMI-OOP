#include "JsonDoubleArray.h"

void JsonDoubleArray::copy(const JsonDoubleArray& other)
{
	Json::copy(other);
	this->value = other.value;
}

JsonDoubleArray::JsonDoubleArray()
{
}

JsonDoubleArray::JsonDoubleArray(std::vector<double> _value)
{
	this->value = _value;
}

JsonDoubleArray::JsonDoubleArray(const JsonDoubleArray& other)
{
	copy(other);
}

JsonDoubleArray& JsonDoubleArray::operator=(const JsonDoubleArray& other)
{
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}

std::vector<double> JsonDoubleArray::getValue() const
{
	return this->value;
}

void JsonDoubleArray::setValue(std::vector<double> _value)
{
	this->value = _value;
}

void JsonDoubleArray::print()
{
	for (int i = 0; i < value.size(); i++)
	{
		std::cout << value[i];
		if (i != value.size() - 1) std::cout << ", ";
	}
}
