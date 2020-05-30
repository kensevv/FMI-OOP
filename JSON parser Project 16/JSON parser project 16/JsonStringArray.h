#pragma once
#include "Json.h"
#include <vector>

class JsonStringArray : public Json
{
private:
	std::vector<std::string> value;
	void copy(const JsonStringArray& other);

public:
	JsonStringArray();
	JsonStringArray(std::vector<std::string> _value);
	JsonStringArray(const JsonStringArray& other);
	JsonStringArray& operator=(const JsonStringArray& other);
	std::vector<std::string> getValue()const;
	void setValue(std::vector<std::string> _value);

	void print() override;
};

