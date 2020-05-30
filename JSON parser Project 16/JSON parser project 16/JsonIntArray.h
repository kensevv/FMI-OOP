#pragma once
#include "Json.h"
#include <vector>

class JsonIntArray : public Json
{
private:
	std::vector<int> value;
	void copy(const JsonIntArray& other);

public:
	JsonIntArray();
	JsonIntArray(std::vector<int> _value);
	JsonIntArray(const JsonIntArray& other);
	JsonIntArray& operator=(const JsonIntArray& other);
	std::vector<int> getValue()const;
	void setValue(std::vector<int> _value);

	void print() override;
};

