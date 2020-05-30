#include "JsonStringArray.h"

void JsonStringArray::copy(const JsonStringArray& other)
{
	Json::copy(other);
	this->value = other.value;
}

JsonStringArray::JsonStringArray()
{
}

JsonStringArray::JsonStringArray(std::vector<std::string> _value)
{
	this->value = _value;
}

JsonStringArray::JsonStringArray(const JsonStringArray& other)
{
	copy(other);
}

JsonStringArray& JsonStringArray::operator=(const JsonStringArray& other)
{
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}

std::vector<std::string> JsonStringArray::getValue() const
{
	return this->value;
}

void JsonStringArray::setValue(std::vector<std::string> _value)
{
	this->value = _value;
}

void JsonStringArray::print()
{
	for (int i = 0; i < value.size(); i++)
	{
		std::cout << value[i];
		if (i != value.size() - 1) std::cout << ", ";
	}
}
