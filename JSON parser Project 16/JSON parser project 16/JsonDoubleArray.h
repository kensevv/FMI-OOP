#pragma once
#include "Json.h"
#include <vector>
#include "Vector.h"

class JsonDoubleArray : public Json
{
private:
	std::vector<double> value;
	void copy(const JsonDoubleArray& other);

public:
	JsonDoubleArray();
	JsonDoubleArray(std::vector<double> _value);
	JsonDoubleArray(const JsonDoubleArray& other);
	JsonDoubleArray& operator=(const JsonDoubleArray& other);
	std::vector<double> getValue()const;
	void setValue(std::vector<double> _value);

	void print() override;
};

